#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid = fork();
  if(pid < 0) {
    printf("fork erro\n");
  }

  if(pid == 0) { // child
    printf("i am child, my pid is %d, my father pid is %d!\n",getpid(), getppid());
  } else {
    printf("i am father, my pid is %d!\n",getpid());
    wait(NULL);
  }

  return 0;
}
