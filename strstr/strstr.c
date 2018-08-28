#include <stdio.h>

char* my_strstr(const char* str1, const char* str2) {
  if (str1 == NULL || str2 == NULL)
    return NULL;

  const char* cur = str1;
  while (*cur) {
    const char* to_find = str2;
    if (*cur == *to_find) {
      const char* tmp = cur;
      while (*tmp++ == *to_find++);
      if (*to_find == '\0')
        return (char*)cur;
    }
    ++cur;
  }
  return NULL;
}

int main()
{
  char str1[] = "abcdefg";
  char str2[] = "cd";
  char* ret = my_strstr(str1, str2);
  printf("%s\n", ret);

  return 0;
}

