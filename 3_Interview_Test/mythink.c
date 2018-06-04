#include <stdio.h>

int Find(int* arr, int sz)
{
  int i = 0;

  for(i = 0; i < sz; ++i) {
    int j = 0;
    for(j = i; j < sz - 1; ++j) {
      if(arr[j] == arr[j+1]) {
        return arr[j];
      }
    }
  }
  return -1;
}

void swap(int* a, int* b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}


int main()
{
  int arr[] = {2,3,1,0,2,5,3};
  int sz = sizeof(arr)/sizeof(arr[0]); 
  int i = 0;

  for(; i < sz; ++i) {
    int j = 0;
    for(j = i; j < sz - 1; ++j) {
      if(arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
  int ret = Find(arr, sz);
  printf("ret expected 2 or 3, ret actual %d\n",ret);

  return 0;
}
