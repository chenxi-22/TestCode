#if 0

#include <iostream>
#include <vector>


typedef int (*Cmpare)(int a, int b);

void test_print(std::vector<int> v) {
  size_t size = v.size();
  for (size_t i = 0; i < size; ++i) {
    std::cout<<v[i]<<" ";
  }
  std::cout<<std::endl;
}

int Greater(int a, int b) {
  return a > b ? 1 : 0;
}

int Less(int a, int b) {
  return a < b ? 1 : 0;
}

class HeapSort {
public:

  Cmpare cmp = Greater;
  void myHeapSort(std::vector<int> v) {
    if (v.size() == 0 || v.size() == 1) return;
    CreateHeap(v, v.size());

    for (size_t i = 0; i < v.size(); ++i) {
      int heap_bound = v.size() - i;
      HeapPop(v, heap_bound);
    }
    test_print(v);
  }

  void CreateHeap(std::vector<int> v, int size) {
    int parent = v.size() / 2 - 1;
    while (parent >= 0) {
      AdjustDown(v, parent, size);
      --parent;
    }
  }

  void AdjustDown(std::vector<int> v, int parent, int size) {
    int child = parent * 2 + 1;
    // int tmp = v[parent];
    while (child < size) {
      if ((child + 1) < size && cmp(v[child], v[child + 1])) child += 1;
      if (cmp(v[parent], v[child]) == 1) {
        // v[parent] = v[child];
        std::swap(v[parent], v[child]);
        parent = child;
      child = parent * 2 + 1;
      } else {
        break;
      }
    } // end while (child < size)
    // v[parent] = tmp;
    return;
  }

  void HeapPop(std::vector<int> v, int heap_bound)
  {
    std::swap(v[0], v[heap_bound - 1]);
    AdjustDown(v, 0, heap_bound - 1);
  }
};

int main()
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(4);
  v.push_back(2);
  v.push_back(9);
  v.push_back(0);
  v.push_back(3);
  HeapSort hs;
  hs.myHeapSort(v);
  // test_print(v);
   
  return 0;
}

#else  


// 构建小堆为降序

#include <stdio.h>
#include <iostream>

void AdjustDown(int* arr, int parent, int size)
{
  if (arr == NULL) return;
  int child = 2 * parent + 1;

  while (child < size) {
    if (child + 1 < size && arr[child] > arr[child + 1]) child += 1;
    if (arr[parent] > arr[child]) {
      std::swap(arr[parent], arr[child]);
      parent = child;
      child = parent * 2 + 1;
    } else {
      break;
    }
  }
  return;
}

void HeapCreat(int* arr, int size)
{
  if (arr == NULL) return;

  int parent = size / 2 - 1;
  for(; parent >= 0; --parent) {
    AdjustDown(arr, parent, size);
  }
  return;
}

void HeapPop(int* arr, int bound)
{
  std::swap(arr[0], arr[bound - 1]);
  AdjustDown(arr, 0, bound - 1);
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
  int arr[] = {1,3,5,2,7,4,9};
  int size = sizeof(arr) / sizeof(arr[0]);

  HeapCreat(arr, size);

  for (int i = 0; i < size; ++i) {
    int bound = size - i;
    HeapPop(arr, bound);
  }

  test_print(arr, size);

  return 0;
}

#endif
