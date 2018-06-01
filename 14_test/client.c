#include <stdio.h>
#include <pthread.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char* argv[])
{
  if(argc != 3) {
    printf("usage %s [IP][port]\n",argv[0]);
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    printf("socket error!\n");
    return 2;
  }

  struct sockaddr_in server;
  bzero(&server, sizeof(server));
  socklen_t len = sizeof(server);
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  server.sin_addr.s_addr = inet_addr(argv[1]);

  if(connect(sock, (struct sockaddr*)&server, len) < 0) {
    printf("connect error!\n");
    return 3;
  }
  
  char buf[64];
  while(1) {
    buf[0] = 0;
    printf("please enter# ");
    fflush(stdout);
    ssize_t s = read(0, &buf, sizeof(buf));
    if(s > 0) {
      buf[s-1] = 0;
      write(sock, &buf, sizeof(buf));
      s = read(sock, &buf, sizeof(buf) - 1);
      if(s > 0) {
        buf[s] = 0;
        printf("server says# %s\n",buf);
      }
    }
  }
  close(sock);

  return 0;
}
