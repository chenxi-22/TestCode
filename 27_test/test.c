#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <sys/timerfd.h>

int main()
{
  int tfd = timerfd_create(CLOCK_MONOTONIC, TFD_CLOEXEC);
  if (tfd == -1) {
    perror("timerfd_create");
    exit(1);
  }

  struct itimerspec isp;
  bzero(&isp, sizeof(isp));
  isp.it_value.tv_sec  = 3;
  isp.it_interval.tv_sec = 1;
  timerfd_settime(tfd, 0, &isp, NULL);

  int kfd = fileno(stdin);
  printf("kfd expect is 0 kfd acutal %d\n", kfd);
  int max_fd = kfd > tfd ? kfd :tfd;

  fd_set set;
  while (1) {
    FD_ZERO(&set);
    FD_SET(tfd, &set);
    FD_SET(kfd, &set);

    int nready = select(max_fd + 1, &set, NULL, NULL, NULL);
    if (nready <= 0) {
      continue;
    }

    if (FD_ISSET(tfd, &set)) {
      uint64_t es;
      int r = read(tfd, &es, sizeof(es));
      if (r < 0) {
        perror("read");
      }
      printf("r = %d\n", r);
    }

    int r;
    if (FD_ISSET(kfd, &set)) {
      char buf[1024];
ret:  r = read(tfd, buf, 1024);
      if (r <= 0) {
        if (r == -1 && errno == EINTR) {
          goto ret;
        }
      }
      printf("buf->%s\n", buf);
    }
  }

  return 0;
}
