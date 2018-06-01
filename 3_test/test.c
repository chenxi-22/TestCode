#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_print2(char* my_string)
{
  char* string2;
  int size, i;
  size = strlen(my_string);
  string2 = (char*)malloc(size+1);

  for(i = 0; i < size; i++) {
    string2[size-i-1] = my_string[i];
  }
  string2[size] = '\0';
  printf("%s\n",string2);
  free(string2);
}

int main()
{
  char my_string[] = "hello world";
  my_print2(my_string);

    return 0;
}
