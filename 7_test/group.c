#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();
  if(pid == 0) {
    while(1) {
      sleep(1);
      printf("i am child ,my pid is %d\n",getpid());
    }
  } else if(pid > 0) {
    int i = 10;
    while(i--) {
      printf("i am father, my pid is %d\n",getpid());
      sleep(1);
    }
  }

  return 0;
}
