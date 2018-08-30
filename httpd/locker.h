#pragma once

#include <pthread.h>

class locker {
public:
  locker() {
    pthread_mutex_init(&_lock, nullptr);
  }

  void lock() {
    pthread_mutex_lock(&_lock);
  }

  void unlock() {
    pthread_mutex_unlock(&_lock);
  }

  ~locker() {
    pthread_mutex_destroy(&_lock);
  }
private:
  pthread_mutex_t _lock;
};

class cond {
public:
  cond() {                                 // 初始化条件变量与互斥锁
    pthread_mutex_init(&_lock, nullptr);   // 这里采用的动态初始化 
    pthread_cond_init(&_cond, nullptr);    // pthread_mutex_init(&_lcok, nullptr);    
  }                                        // pthread_cond_init(&_cond, nullptr);

  bool signal() {
     return pthread_cond_signal(&_cond);   // 唤醒一个目标, 防惊群
  }

  void wait() {
    pthread_cond_wait(&_cond, &_lock);
  }

  void lock() {
    pthread_mutex_lock(&_lock);
  }

  void unlock() {
    pthread_mutex_unlock(&_lock);
  }

  ~cond() {
    pthread_mutex_destroy(&_lock);         // 如果是静态初始化的不需要 destroy
    pthread_cond_destroy(&_cond);
  }
private:
  pthread_mutex_t _lock;  
  pthread_cond_t  _cond;
};


