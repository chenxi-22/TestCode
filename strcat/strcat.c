#include <stdio.h>

char* my_strcat(char* buff, const char* str) {
  if (buff == NULL || str == NULL)
    return buff;

  char* dst = buff;
  const char* src = str;
  while (*dst)
    ++dst;
  while (*src) {
    *dst++ = *src++;
  }

  return buff;
}

int main()
{
  char buff[64] = "hello";
  char str[] = "world";
  my_strcat(buff, str);
  printf("%s\n", buff);

  return 0;
}

