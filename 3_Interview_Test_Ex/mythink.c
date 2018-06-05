#include <stdio.h>
#include <string.h>

int FindSameNum(int* tmp, int sz)
{
  if(tmp == NULL || sz == 0) {
    return -1;
  }

  int i = 0;
  for(; i < sz; ++i) {
    int cur = tmp[i];
    while(tmp[i] != i) {
      if(tmp[i] == tmp[cur]) {
        return tmp[i];
      }
      tmp[i] = tmp[cur];
      tmp[cur] = cur;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {2,3,5,4,3,2,6,7};
  int sz = sizeof(arr)/sizeof(arr[0]);
  int tmp[sz];
  memmove(tmp, arr, sz);//利用memmove进行拷贝

  int ret = FindSameNum(tmp, sz);
  printf("ret expected 2 or 3, ret actual %d\n",ret);

  return 0;
}
