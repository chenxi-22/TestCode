#include <iostream>
#include <pthread.h>

using namespace std;

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_t lock2;

void* handler(void* arg) {
  arg = (void*)arg;
  pthread_mutex_lock(&lock1);
  cout << "get lock" << endl;

  return NULL;
}

int main()
{
  pthread_t tid1;
  
  pthread_mutex_lock(&lock1);
  
  pthread_create(&tid1, NULL, handler, NULL);
  pthread_join(tid1, NULL);
  pthread_mutex_unlock(&lock1);

  return 0;
}
