#include <stdio.h>
#include <string.h>

void* my_memcpy(void* dst, const void* src, size_t n) {
  if (dst == NULL || src == NULL || n == 0)
    return dst;

  char* str1 = (char*)dst;
  const char* str2 = (const char*)src;
  while (n--) {
    if (*str2 == '\0') 
      return dst;
    *str1++ = *str2++;
  }
  return dst;
}

int main()
{
  char dst[64] = {0};
  char src[] = "hello world!";

  my_memcpy(dst, src, 0);
  printf("%s\n", dst);

  return 0;
}



