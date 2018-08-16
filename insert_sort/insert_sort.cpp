#include <iostream>

// 插入排序
// 时间复杂度 O(N^2)
// 空间复杂度 O1
// 稳定排序
void insert_sort(int* arr, int size)
{
  if (arr == NULL) return;
  int bound = 1;
  for (; bound < size; ++bound) {
    int tmp = arr[bound];
    int cur = bound - 1;
    while (cur >= 0 && tmp < arr[cur]) {
      arr[cur + 1] = arr[cur];
      --cur;
    }
    arr[cur + 1] = tmp;
  }
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
  int arr[] = {4,3,1,6,3,8,0};
  int size = sizeof(arr) / sizeof(arr[0]);

  insert_sort(arr, size);
  test_print(arr, size);
}
