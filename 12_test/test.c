#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  struct sockaddr_in addr1;
  struct sockaddr_in addr2;
  inet_aton("127.0.0.1",&addr1.sin_addr);
  inet_aton("111.1.1.0",&addr2.sin_addr);
  printf("addr1:%s addr2:%s",inet_ntoa(addr2.sin_addr),
          inet_ntoa(addr1.sin_addr));

  return 0;
}
