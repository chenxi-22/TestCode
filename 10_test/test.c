#include <stdio.h>

int main()
{
  int arr[4] = {1,2,3,4};
  int* ptr1 = (int*)(&arr + 1);
  int* ptr2 = (arr + 1);
  printf("%x %x\n",ptr1[-1], *ptr2);

  return 0;
}


