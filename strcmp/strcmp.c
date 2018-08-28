#include <stdio.h>
#include <assert.h>
#include <string.h>

int my_strcmp(const char* str1, const char* str2) {
    assert(str1 != NULL && str2 != NULL);
    while (*str1 && *str2) {
      if (*str1 > *str2)
        return 1;
      else if (*str1 < *str2)
        return -1;
      ++str1;
      ++str2;
    }
    if (*str1)
      return 1;
    if (*str2)
      return -1;
    return 0;
}

int main()
{
  char str[] = "abfdfdcd"; 
  char cmp[] = "abcd";
  int ret = my_strcmp(str, cmp);
  printf("%d\n", ret);
  
  return 0;
}
