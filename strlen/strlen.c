#include <stdio.h>
#include <string.h>
#include <assert.h>

size_t my_strlen(const char* str) {
  assert(str != NULL);

  size_t len = 0;
  while (*str) {
    ++len;
    ++str;
  }
  return len;
}

size_t my_strlen2(const char* str) {
  if (str == NULL) 
    return 0;
  if (*str == '\0')
    return 0;
  return 1 + my_strlen2(str + 1);
}

int main()
{
  char str[] = "hello world!";
  // char* str = NULL;
  size_t size = my_strlen2(str);
  printf("%lu\n", size);
  printf("%lu\n", strlen(str));

  return 0;
}

