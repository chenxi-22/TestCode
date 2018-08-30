#include "thread_pool.h"

thread_pool::thread_pool() 
  :_num(THREADSIZE)
   ,_tid(nullptr)
   ,_epfd(nullptr)
   ,_is_destroy(false)
{
  if (_num <= 0)
    throw std::exception();

  _epfd = new epfd_type[EPOLLFDSIZE];
  _tid = new thread_num[THREADSIZE]; 
  _lock = new locker[LOCKNUM];

  for (size_t i = 0; i < EPOLLFDSIZE; ++i) {
    _epfd[i] = epoll_create1(0);

    if (_epfd[i] < 0) 
      throw std::exception();
  }

  for (size_t i = 0; i < THREADSIZE; ++i) {
    Arg* arg = new Arg;
    arg->_epfd = _epfd[i];
    arg->_lock = _lock[i];
    if (pthread_create(_tid + i, nullptr, work, (void*)arg) != 0) {
      delete[] _tid;
      throw std::exception();
    }

    if (pthread_detach(_tid[i]) != 0) {
      delete[] _tid;
      throw std::exception();
    }
  }
}

void* thread_pool::work(void* arg) {
  if (arg == nullptr)
    return nullptr;

  Arg* cur = (Arg*)arg;
  epfd_type epfd = cur->_epfd;
  locker lock = cur->_lock;
  ev_type* events = new ev_type[EVENTSNUM];

  while (1) {
    int ret = epoll_wait(epfd, events, EVENTSNUM, -1);
    if (ret < 0) 
      throw std::exception();

    for (int i = 0; i < ret; ++i) {
      if (events[i].events == EPOLLERR)
        continue;
      if (events[i].events == EPOLLIN) {
        // http
        lock.lock();
        int ret = epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, nullptr);
        if (ret < 0) {
          std::cout << "epoll_ctl()" << std::endl;
        }
        lock.unlock();
      }
    }
  }

  return nullptr;
}

/* 此处为主线程调用，来分发任务的，此时的任务都是
 * 正常的sock，没有 listen_sock，所以工作线程只需
 * 要等待事件就绪，然后去处理即可。
 *
 * 这里的分配其实可以设计一个算法去完成分配，但是
 * 思考半天没有想到一个合理的算法，这里合理的算法
 * 意思是能够让各个工作线程负载均衡。不会造成线程
 * 累死的这种情况出现。
 *
 * 最终我采用以下两种方式进行分配：
 * a. 采用轮询式分配，第一次分配从下标为 0 的开始
 *    分配，分配完毕记录下标。下次主线程分配的时,
 *    继续从上次的结束地方开始分配，如果下标超过 
 *    THREADSIZE 那么继续从 0 开始即可。                  
 *
 * b. 采用随机分配制度。也就是说定义一个产生随机
 *    数的函数，种上时间种子。产生随机数，用这个
 *    随机数每次 % THREADSIZE 就是对应下标，对这
 *    个下标进行分配。                         */

// a 方式:
bool thread_pool::set_events(ev_type* ev, int size) {
  if (ev == nullptr || size == 0)
    return false;

  srand(time(nullptr));
  int n = -1;
  epfd_type epfd = -1;
  for (int i = 0; i < size; ++i) {       
    n = rand() % 5;
    epfd = _epfd[n];
  }

  return true;
}

thread_pool::~thread_pool() {
  delete[] _tid;
  delete[] _epfd;
  _is_destroy = true;
}
