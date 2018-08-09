#include <iostream>

void select_sort(int* arr, int size) {
  if (arr == NULL) return;

  int bound = 0;
  for(; bound < size; ++bound) {
    int cur = size - 1;
    for (; cur > bound; --cur) {
      if (arr[bound] > arr[cur]) {
        std::swap(arr[bound], arr[cur]);
      }
    }
  }
}

void test_print(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int main()
{
  int arr[] = {9,3,1,4,8,5,7,0};
  int size = sizeof(arr) / sizeof(arr[0]);

  select_sort(arr, size);

  test_print(arr, size);

  return 0;
}


