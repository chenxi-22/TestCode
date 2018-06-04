#include <stdio.h> 

int FindSameArr(int arr[], int size)
{
  if(arr == NULL) {
    return -1;
  }

  int i = 0;
  for(; i < size; ++i) {
    int tmp = arr[i];
    while(arr[i] != i) {
      if(arr[i] == arr[tmp]) {
        return arr[i];
      }
      arr[i] = arr[tmp];
      arr[tmp] = tmp;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {2,3,1,0,2,5,3};
  int size = sizeof(arr)/sizeof(arr[0]);

  int ret = FindSameArr(arr, size);
  printf("expect ret 3 or 2,actual ret %d\n",ret);

  return 0;
}


