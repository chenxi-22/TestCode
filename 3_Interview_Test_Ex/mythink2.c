#include <stdio.h>
#include <string.h>

int FindSameNum(int* arr, int sz)
{
  if(arr == NULL || sz == 0) {
    return -1;
  }
  int i = 0;
  int tmp[sz];
  memset(tmp, 0, 4*sz);//初始化为0

  for(; i < sz; ++i) {
    int cur = arr[i];
    if(tmp[cur] == 0) {
      tmp[cur] = arr[i];
    } else {
      return arr[i];
    }
  }
  return -1;
}

int main()
{
  int arr[] = {2,3,5,4,3,2,6,7};
  int sz = sizeof(arr)/sizeof(arr[0]);

  int ret = FindSameNum(arr, sz);
  printf("ret expected 2 or 3, ret actual %d\n",ret);

  return 0;
}
