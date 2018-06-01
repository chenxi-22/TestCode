#include <stdio.h>
#include <pthread.h>

void* thread1(void* arg)
{
  printf("i am %s!\n",(char*)arg);

  return (void*)0;
}

void* thread2(void* arg)
{
  printf("i am %s!\n",(char*)arg);

  return (void*)0;
}

void* thread3(void* arg)
{
  printf("i am %s!\n",(char*)arg);

  return (void*)0;
}

int main()
{
  pthread_t tid1, tid2, tid3;

  pthread_create(&tid1, NULL, thread1, (void*)"thread1");
  pthread_create(&tid2, NULL, thread2, (void*)"thread2");
  pthread_create(&tid3, NULL, thread3, (void*)"thread3");

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);

  return 0;
}



