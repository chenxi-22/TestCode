#include <iostream>
#include <pthread.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

pthread_mutex_t lock1;

void* handler(void*) {
  cout << "----------------------------------------------" << endl;
  pthread_mutex_lock(&lock1);

  cout <<  " i am here" << endl;
  return NULL;
}

int main() 
{

  cout << "==============================================" << endl;
  pthread_mutex_init(&lock1, NULL);
  cout << "==============================================" << endl;
  pthread_mutex_lock(&lock1);
  pthread_t tid;
  cout << "==============================================" << endl;
  pthread_create(&tid, NULL, handler, NULL);
  cout << "==============================================" << endl;
  pthread_join(tid, NULL);

  return 0;
}

