#pragma once

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

#include <pthread.h>
#include <sys/epoll.h>

#include "locker.h"

enum { THREADSIZE = 5 };                // 线程池总线程数
enum { EPOLLFDSIZE = THREADSIZE };      // epoll 句柄的个数
enum { EVENTSNUM = 256 };               // struct epoll_event 数组大小
enum { LOCKNUM = THREADSIZE };          // 线程锁的数量
 
typedef size_t thread_num;              // 线程数量类型
typedef int    epfd_type;               // epoll 句柄类型
typedef bool   tp_state;                // 线程池状态

typedef struct epoll_event ev_type;     // struct epoll_event 类型

struct Arg {                            // 参数类
  epfd_type _epfd;
  locker _lock;
};

class thread_pool {
public:
  thread_pool();
  bool set_events(ev_type* ev, int size);
  ~thread_pool();
private:
  static void* work(void*);
private:
  locker* _lock;                        // 线程锁
  thread_num _num;                      // 线程数
  pthread_t* _tid;                      // 线程 id 数组
  epfd_type* _epfd;                     // epoll 句柄数组
  tp_state _is_destroy;                 // 线程池是否销毁
};


