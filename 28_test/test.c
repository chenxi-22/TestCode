#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <fcntl.h>

int GetFile(int sock, char* filename)
{
  char buf[2014];
  int fd = open(filename, O_RDONLY | O_WRONLY, 0666);
  if (fd < 0) {
    perror("open");
    return 0;
  }

  int old_flag = fcntl(sock, F_GETFL, 0);
  int new_flag = old_flag | O_NONBLOCK;
  fcntl(sock, F_SETFL, new_flag);

  char check[3] = {0};
  while (1) {
    ssize_t s = recv(sock, check, sizeof(check), MSG_PEEK);
    if (s > 0) {
      break;
    }
  }

  while (1) {
    ssize_t s = read(sock, buf, sizeof(buf));
    if (s <= 0) {
      perror("read");
      fcntl(sock, F_SETFL, old_flag);
      break;
    } else {
      write(fd, buf, strlen(buf));
    }
  } // end while (1)

  return 1;
}

int PutFile(int sock, char* filename)
{
  int fd = open(filename, O_RDONLY | O_WRONLY);
  if (fd < 0) {
    perror("open");
    return 0;
  }

  struct stat st;
  if (stat(filename, &st) == -1) {
    perror("stat");
    return 0;
  }

  int size = st.st_size;
  ssize_t ret = sendfile(fd, sock, NULL, size);
  if (ret < 0) {
    perror("sendfile");
    return 0;
  }

  return 1;
}


