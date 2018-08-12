#include <iostream>
#include <string.h>
#include <stdlib.h>

void MergeArray(int array[], int beg, int mid, int end, int* tmp)
{
  int index = beg;
  int cur1 = beg;
  int cur2 = mid;
  while (cur1 < mid && cur2 < end) {
    if (array[cur1] < array[cur2]) {
      tmp[index++] = array[cur1++];
    } else {
      tmp[index++] = array[cur2++];
    }
  }
  while (cur1 < mid) {
    tmp[index++] = array[cur1++];
  }
  while (cur2 < end) {
    tmp[index++] = array[cur2++];
  }
  memcpy(array + beg, tmp + beg, (end - beg)*sizeof(int));
  return;
}

//void merge_array(int* arr, int beg, int mid, int end, int* tmp)
//{
//  int index = beg;
//  int cur1 = beg;
//  int cur2 = mid;
//  while (cur1 < mid && cur2 < end) {
//    if (arr[cur1] < arr[cur2]) {
//      tmp[index++] = arr[cur1++];
//    } else {
//      tmp[index++] = arr[cur2++];
//    }
//  }
//  while (cur1 < mid) {
//    tmp[index++] = arr[cur1++];
//  }
//  while (cur2 < mid) {
//    tmp[index++] = arr[cur2++];
//  }
//  return;
//  memcpy(arr + beg, tmp + beg, sizeof(int) * (end - beg));
//}

void merge_array(int arr[], int beg, int mid, int end, int* tmp)
{
  int index = beg;
  int cur1 = beg;
  int cur2 = mid;
  while (cur1 < mid && cur2 < end) {
    if (arr[cur1] < arr[cur2]) {
      tmp[index++] = arr[cur1++];
    } else {
      tmp[index++] = arr[cur2++];
    }
  }
  while (cur1 < mid) {
    tmp[index++] = arr[cur1++];
  } 
  while (cur2 < mid) {
    tmp[index++] = arr[cur2++];
  }
  memcpy(arr + beg, tmp + beg, sizeof(int) * (end - beg));
}

void MergeSortByLoop(int arr[], int size)
{
  if (size <= 1) {
    return;
  }
  int size_bound = 1;
  int* tmp = (int*)malloc(sizeof(int) * size);
  for (; size_bound < size; size_bound *= 2) {
    int i = 0;
    for (; i < size; i += 2 * size_bound) {
      int beg = i;
      int mid = beg + size_bound;
      int end = mid + size_bound;
      
      // 如果此时的 mid 超过了 size 
      // 那么就意味着此时的区间只剩下了一个
      // 即 [beg, mid) 那么这个时候 
      // mid 需要置为 size 防止越界
      if (mid >= size) { 
        mid = size;
      }
      
      // 这里同理，如果 end 超过了 size 
      // 那么就是第二段的区域的元素个数低于第一段
      // 也需要将 end 置为 size
      if (end >= size) {
        end = size;
      }
      MergeArray(arr, beg, mid, end, tmp);
    } // end for (; i < size; i += 2 * size_bound)
  }
  return;
}

void merge_sort_by_loop(int* arr, int size)
{
  if (arr == NULL) return;
  int* tmp = (int*)malloc(sizeof(int) * size);
  if (tmp == NULL) return;

  int order_bound = 1;
  for (; order_bound < size; order_bound *= 2) {
    for (int cur = 0; cur < size; cur += 2 * order_bound) {
      int beg = cur;
      int mid = beg + order_bound;
      int end = mid + order_bound;
      if (mid >= size) mid = size;
      if (end >= size) end = size;
      //MergeArray(arr, beg, mid, end, tmp);
      merge_array(arr, beg, mid, end, tmp);
    }
  }
  free(tmp);
  tmp = NULL;
}
void _merge_sort(int* arr, int beg, int end, int* tmp) 
{
  if (arr == NULL || tmp == NULL) return;
  if (beg >= end - 1) return;
  int mid = beg + (end - beg) / 2;
  _merge_sort(arr, beg, mid, tmp);
  _merge_sort(arr, mid, end, tmp);
  //merge_array(arr, beg, mid, end, tmp);
  MergeArray(arr, beg, mid, end, tmp);
}

void merge_sort(int* arr, int size) 
{
  if (arr == NULL) return;
  int beg = 0;
  int end = size;
  int* tmp = (int*)malloc(sizeof(int) * size);
  _merge_sort(arr, beg, end, tmp);
  free(tmp);
  tmp = NULL;
}

void test_print(int* arr, int size) 
{
  if (arr == NULL) return;
  for (int i = 0; i < size; ++i) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int main()
{
  int arr[] = {4,2,1,7,4,0,3};
  int size = sizeof(arr) / sizeof(arr[0]);

  merge_sort(arr, size);
  //merge_sort_by_loop(arr, size);
  //MergeSortByLoop(arr, size);
  test_print(arr, size);
}
