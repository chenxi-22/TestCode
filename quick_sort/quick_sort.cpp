#include <iostream>
#include <stack>
#include <unistd.h>

int dig_val(int* arr, int left, int right)
{
  if (arr == NULL) return -1;

  right = right - 1;
  int key = arr[right];
  while (left < right) {
    while (left < right && arr[left] <= key) {
      ++left;
    }
    if (left < right) {
      arr[right] = arr[left];
      --right;
    }
    while (left < right && arr[right] >= key) {
      --right;
    }
    if (left < right) {
      arr[left] = arr[right];
      ++left;
    }
  }
  arr[left] = key;
  return left;
}


int exchage_val(int* arr, int left, int right)
{
  if (arr == NULL) return -1;
  int end = right - 1;
  int key = arr[right - 1];
  right = right - 1;

  while (left < right) {
    while (left < right && arr[left] <= key) {
      ++left;
    }
    while (left < right && arr[right] >= key) {
      --right;
    }
    if (left < right) {
      std::swap(arr[right], arr[left]);
    }
  }
  std::swap(arr[right], arr[end]);
  return right;
}

void _quick_sort(int* arr, int left, int right)
{
  if (arr == NULL) return;
  if (left >= right) return;
  //int mid = exchage_val(arr, left, right);
  int mid = dig_val(arr, left, right);
  _quick_sort(arr, left, mid);
  _quick_sort(arr, mid + 1, right);
}

void quick_sort(int* arr, int size)
{
  if (arr == NULL) return;
  int left = 0;
  int right = size;
  _quick_sort(arr, left, right);
}

void quick_sort_by_loop(int* arr, int size)
{
  if (arr == NULL) return;
  int left = 0;
  int right = size;
  std::stack<int> s;
  s.push(left);
  s.push(right);

  while (!s.empty()) {
    right = s.top();
    s.pop();
    left = s.top();
    s.pop();
    sleep(1);
    std::cout<<"left="<<left<<" right="<<right<<std::endl;
    int mid = dig_val(arr, left, right);
    std::cout<<"left="<<left<<" right="<<right<<std::endl;
    s.push(left);
    s.push(mid);
    s.push(mid+1);
    s.push(right);
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

  quick_sort(arr, size);
  //quick_sort_by_loop(arr, size);

  test_print(arr, size);

  return 0;
}



