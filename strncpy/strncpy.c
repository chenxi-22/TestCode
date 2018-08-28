#include <stdio.h>

char* my_strncpy(char* dst, const char* src, size_t n) {
  if (dst == NULL || src == NULL || n == 0) 
    return dst;

  char* buff = dst;
  while (n--) {
    *buff++ = *src++;
  }
  return dst;
}

int main()
{
  char buff[64] = {0};
  char str[] = "hello world!";
  my_strncpy(buff, str, 5);
  printf("%s\n", buff);

  return 0;
}
