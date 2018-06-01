#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

int StartUp(char* ip, char* port)
{
  if(ip == NULL || port == NULL) {
    return -1;
  }
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in local;
  bzero(&local, sizeof(local));
  local.sin_family = AF_INET;
  local.sin_addr.s_addr = inet_addr(ip);
  local.sin_port = htons(atoi(port));

  if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0) {
     perror("bind");
     exit(2);
  }

  if(listen(sock, 5) < 0) { 
    perror("listen");
    exit(3);
  }
  return sock;
}

int main(int argc, char* argv[])
{
  if(argc != 3) {
    printf("usage %s [IP][port]\n",argv[0]);
    return 1;
  }
  int listen_sock = StartUp(argv[1], argv[2]);

  char buf[64];
  struct sockaddr_in client;
  socklen_t len = sizeof(client);

  while(1) {
    pid_t pid = fork();
    if(pid == 0) {
      if(fork() == 0) {
        int sock = accept(listen_sock, (struct sockaddr*)&client, &len);
        if(sock < 0) {
          perror("accept");
          continue;
        }
        while(1) {
          ssize_t s = read(sock, &buf, sizeof(buf) - 1);
          if(s > 0) {
            buf[s] = 0;
            printf("client says# %s\n",buf);
            write(sock, &buf, sizeof(buf));
          }
        }
      } else {
        exit(0);//第一子进程退出由其父进程回收，而其子进程为孤儿进程，由一号进程回收。
      }
    } else {
      waitpid(pid, NULL, 0);//等待
    }
  }

  return 0;
}


