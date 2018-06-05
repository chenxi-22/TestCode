#include <stdio.h>

int Count(int* arr, int sz, int start, int mid)
{
  if(arr == NULL || sz <= 0) {
    return -1;
  }

  int count = 0;
  sz -= 1;
  while(sz--) {
    if(arr[sz] >= start && arr[sz] <= mid) {
      count++;
    }
  }
  return count;
}

int FindSameNum(int* arr, int sz)
{
  if(arr == NULL || sz <= 0) {
    return -1;
  }

  int start = 1;
  int end = sz - 1;
  while(start <= end) {
    int mid = ((end - start)>>1) + start;
    int count = Count(arr, sz, start, mid);

    if(start == end) {
      if(count > 1) {
        return start;
      } else {
        break;
      }
    }

    if(count > (mid - start + 1)) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {2,3,1,4,4,5,6,7};
  int sz = sizeof(arr)/sizeof(arr[0]);

  int ret = FindSameNum(arr, sz);
  printf("ret expected 4, ret actual %d\n",ret);

  return 0;
}
