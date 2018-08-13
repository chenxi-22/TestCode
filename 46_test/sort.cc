#include <iostream>
#include <string.h>

void shell_sort(int* arr, size_t size) {
  if (arr == NULL)
    return;

  int gap = size / 2;
  for (; gap >= 1; gap /= 2) {
    for (int cur = 0; cur < gap; ++cur) {
      size_t bound = cur + gap;
      for (; bound < size; bound += gap) {
        size_t i = bound - gap;
        int key =  arr[bound];
        while (i >= 0 && arr[i] > key) {
          arr[i + gap] = arr[i];
          i -= gap;
        }
        arr[i + gap] = key;
      }
    }
  }
}

void merge_array(int* arr, size_t left, size_t mid, size_t right, int* tmp) {
  if (arr == NULL || tmp == NULL) 
    return;

  size_t index = left;
  size_t cur1 = left;
  size_t cur2 = mid;
  while (cur1 < mid && cur2 < right) {
    if (arr[cur1] < arr[cur2])
      tmp[index++] = tmp[cur1++];
    else
      tmp[index++] = tmp[cur2++];
  }

  while (cur1 < mid)
    tmp[index++] = arr[cur1++];
  while (cur2 < right) 
    tmp[index++] = arr[cur2++];

  memcpy(arr + right, tmp + right, sizeof(int) * (right - left));
}

void _merge_sort(int* arr, size_t left, size_t right, int* tmp) {
  if (arr == NULL || tmp == NULL 
      || left >= right - 1) 
    return;

  size_t mid = left + (right - left) / 2;
  _merge_sort(arr, left, mid, tmp);
  _merge_sort(arr, mid, right, tmp);
  merge_array(arr, left, mid, right, tmp);
}

void merge_sort(int* arr, size_t size) {
  if (arr == NULL)
    return;

  size_t left = 0;
  size_t right = size;
  int* tmp = (int*)malloc(sizeof(int) * size);
  _merge_sort(arr, left, right, tmp);
}

void adjust_down(int* arr, size_t parent, size_t size) {
  if (arr == NULL) 
    return;

  size_t child = 2 * parent + 1;
  while (child < size) {
    if (child + 1 < size && arr[child] < arr[child + 1]) 
      child += 1;
    if (arr[parent] < arr[child]) {
      std::swap(arr[parent], arr[child]);
      parent = child;
      child = 2 * parent + 1;
    } else {
      break;
    }
  }
}

void heap_create(int* arr, int size) {
  if (arr == NULL) 
    return;

  size_t parent = size / 2 - 1;
  for (; parent >= 0; --parent) {
    adjust_down(arr, parent, size);
  }
}

void heap_pop(int* arr, size_t size) {
  if (arr == NULL) 
    return;

  for (size_t i = 0; i < size; ++i) {
    size_t bound = size - i;
    std::swap(arr[bound - 1], arr[0]);
    adjust_down(arr, 0, bound - 1);
  }
}

void heap_sort(int* arr, size_t size) {
  if (arr == NULL) 
    return;

  heap_create(arr, size);
  heap_pop(arr, size);
}

size_t exchange_val(int* arr, int left, int right) {
  if (arr == NULL) 
    return (size_t)-1;

  right -= 1;
  int tmp = right;
  int key = arr[right];
  while (left < right) {
    while (left < right && arr[left] <= key) {
      ++left;
    }
    while (left < right && arr[right] >= key) {
      --right;
    }
    if (left < right) {
      std::swap(arr[left], arr[right]);
    }
  }
  std::swap(arr[tmp], arr[right]);
  return right;
}

void _quick_sort(int* arr, int left, int right) {
  if (arr == NULL || left >= right) 
    return;

  size_t mid = exchange_val(arr, left, right);
  _quick_sort(arr, left, mid);
  _quick_sort(arr, mid + 1, right);
}

void quick_sort(int* arr, size_t size) {
  if (arr == NULL)
    return;

  size_t left = 0;
  size_t right = size;
  _quick_sort(arr, left, right);
}


void test_print(int* arr, int size) {
  if (arr == NULL)
    return;

  for (int i = 0; i < size; ++i) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int main()
{
  int arr[] = {3,1,2,7,5,3,9,0};
  size_t size = sizeof(arr)/sizeof(arr[0]);

  quick_sort(arr, size);
  test_print(arr, size);

  return 0;
}








