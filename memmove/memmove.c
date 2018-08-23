#include <stdio.h>
#include <string.h>

void* my_memmove(void* dst, const void* src, size_t n) {
  if (dst == NULL || src == NULL || n == 0 || src == dst) 
    return dst;

  char* buff = (char*)dst; 
  const char* str = (const char*) src; 
  if (buff < str) {   // 如果 src 与 dst 不冲突
    while (n--) {     // 正常复制即可
      *buff++ = *str++;
    }           
  } else {            // 如果 src 与 dst 冲突
    while (n--) {     // 从后往前复制
      *(buff + n) = *(str + n);
    } 
  }

  return dst;
}

int main()
{
  char str[] = "hello world!!!";
  char str1[] = "hello world!!!";
  my_memmove(str + 4, str, 0);
  memmove(str1 + 4, str1, 0);
  printf("%s\n", str);
  printf("%s\n", str1);

  return 0;
}


