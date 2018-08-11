#include <iostream>

// 希尔排序
// 时间复杂度：选择最好的序列 O(N^1.3)
//             最差 O(N^2)
// 空间复杂度：O1
// 不稳定排序


void  shell_sort(int* arr, int size)
{
  if (arr == NULL) return;

  int gap = size / 2;

  for (; gap > 0; gap /= 2) {
    int cur = 0;
    for (; cur < gap; ++cur) {
      int order_bound = cur + gap;
      for (; order_bound < size; order_bound += gap) {
        int tmp = arr[order_bound];
        int index = order_bound - gap;
        while (index >= 0 && arr[index] > tmp) {
          arr[index + gap] = arr[index];
          index -= gap;
        }
        arr[index + gap] = tmp;
      }
    } // end for(; cur < gap; ++cur)
  }

}

void test_print(int* arr, int size)
{
  for (int i = 0; i < size; ++i) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int main()
{
  int arr[] = {4,1,2,9,0,7,3};
  int size = sizeof(arr) / sizeof(arr[0]);

  shell_sort(arr, size);
  test_print(arr, size);

  return 0;
}

