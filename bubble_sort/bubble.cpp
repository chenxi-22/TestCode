#include <iostream>

void test_print(int* arr, size_t size)
{
  for (size_t i = 0; i < size; ++i) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

void bubble_sort(int* arr, size_t size)
{
  if (arr == NULL) return;
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size - i - 1; ++j) {
      if (arr[j] < arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }

  return;
}

int main()
{
  int arr[] = {1,3,4,2,7,5,9};
  int size = sizeof(arr)/sizeof(arr[0]);

  bubble_sort(arr, size);

  test_print(arr, size);

  return 0;
}
