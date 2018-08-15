#include <iostream>
#include <string.h>
#include <stdlib.h>

class HeapSort {
public:
  void heap_sort(int* arr, int size) {
    if (arr == NULL) return;
    heap_create(arr, size);
    heap_pop(arr, size);
  }

  void adjust_down(int* arr, int parent, int size) {
    int child = 2 * parent + 1;
    while (child < size) {
      if (child + 1 < size && arr[child] < arr[child + 1]) child += 1;
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
    int parent = size / 2 - 1;
    for (; parent >= 0; --parent) {
      adjust_down(arr, parent, size);
    }
  }

  void heap_pop(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
      int bound = size - i;
      std::swap(arr[0], arr[bound - 1]);
      adjust_down(arr, 0, bound - 1);
    }
  }
};

class BubbleSort {
public:
  void bubble_sort(int* arr, int size) {
    if (arr == NULL) return;

    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size - i - 1; ++j) {
        if (arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
        }
      }
    }
    return;
  }
};

class InsertSort {
public:
  void insert_sort(int* arr, int size) {
    if (arr == NULL) return;
    for (int bound = 1; bound < size; ++bound) {
      int cur_val = arr[bound];
      int i = bound - 1;
      while (i >= 0 && arr[i] > cur_val) {
        arr[i + 1] = arr[i];
        --i;
      }
      arr[i + 1] = cur_val;
    }
  }
};

class SelectSort {
public:
  void select_sort(int* arr, int size) {
    if (arr == NULL) return;
    int bound = 0;
    for (; bound < size; ++bound) {
      for (int cur = bound + 1; cur < size; ++cur) {
        if (arr[bound] > arr[cur]) std::swap(arr[cur], arr[bound]);
      }
    }
  }
};

class MergeSort {
public:
  void merge_sort_by_loop(int* arr, int size) {
    if (arr == NULL) return;
    int* tmp = (int*)malloc(sizeof(int) * size);
    if (tmp == NULL) return;

    int order_bound = 1;
    for (; order_bound < size; order_bound *= 2) {
      for (int cur = 0; cur < size; cur += order_bound * 2) {
        int beg = cur;
        int mid = cur + order_bound;
        int end = mid + order_bound;
        if (mid >= size) mid = size;
        if (end >= size) end = size;
        merge_array(arr, beg, mid, end, tmp);
      }
    }
  }

  void merge_sort(int* arr, int size) {
    if (arr == NULL) return;
    int beg = 0;
    int end = size;
    int* tmp = (int*)malloc(sizeof(int) * size);
    _merge_sort(arr, beg, end, tmp);
    free(tmp);
  }

  void _merge_sort(int* arr, int beg, int end, int* tmp) {
    if (tmp == NULL) return;
    if (beg >= end - 1) return;
    int mid = (end - beg) / 2 + beg;
    _merge_sort(arr, beg, mid, tmp);
    _merge_sort(arr, mid, end, tmp);
    merge_array(arr, beg, mid, end, tmp);
  }

  void merge_array(int* arr, int beg, int mid, int end, int* tmp) {
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
    memcpy(arr + beg, tmp + beg, (end - beg) * sizeof(int));
  }
};

class ShellSort {
public:
  void shell_sort(int* arr, int size) {
    if (arr == NULL) return;

    int gap = size / 2;

    for (; gap > 0; gap /= 2) {
      int cur = 0;
      for (; cur < gap; ++cur) {
        int bound = cur + gap;
        for (; bound < size; bound += gap) {
          int i = bound - gap;
          int tmp = arr[bound];
          while (i >= 0 && arr[i] > tmp) {
            arr[i + gap] = arr[i];
            i -= gap;
          }
          arr[i + gap] = tmp;
        }
      }
    }
  }
};

void test_print(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

class QuickSort {
public:
  void quick_sort(int* arr, int size) {
    if (arr == NULL) return;
    int beg = 0;
    int end = size;
    _quick_sort(arr, beg, end);
  }

  void _quick_sort(int* arr, int beg, int end) {
    if (beg >= end -1) return;
    // int mid = dig_val(arr, beg, end);
    int mid = exchange_val(arr, beg, end);
    _quick_sort(arr, beg, mid);
    _quick_sort(arr, mid + 1, end);
  }

  int exchange_val(int* arr, int beg, int end) {
    end -= 1;
    int key = arr[end];
    int cur = end;
    while (beg < end) {
      while (beg < end && arr[beg] <= key) {
        ++beg;
      }
      while (beg < end && arr[end] >= key) {
        --end;
      }
      if (beg < end) std::swap(arr[beg], arr[end]);
    }
    std::swap(arr[cur], arr[beg]);

    return beg;
  }
  
  int dig_val(int* arr, int beg, int end) {
    int key = arr[end - 1];
    end -= 1;
    while (beg < end) {
      while (beg < end && arr[beg] <= key) ++beg;
      if (beg < end) {
        arr[end] = arr[beg];
        --end;
      }
      while (beg < end && arr[end] >= key) --end;
      if (beg < end) {
        arr[beg] = arr[end];
        ++beg;
      }
    }
    arr[beg] = key;
    return beg;
  }
};

int main() 
{
  int arr[] = {4,2,1,7,4,0,3};
  int size = sizeof(arr) / arr[0];

  // HeapSort hs;
  // hs.heap_sort(arr, size);

  // BubbleSort bs;
  // bs.bubble_sort(arr, size);

  // InsertSort is;
  // is.insert_sort(arr, size);

  // SelectSort ss;
  // ss.select_sort(arr, size);

  // MergeSort ms;
  // ms.merge_sort_by_loop(arr, size);
  // ms.merge_sort(arr, size);

  // ShellSort ss;
  // ss.shell_sort(arr, size);
   
  QuickSort qs;
  qs.quick_sort(arr, size);

  test_print(arr, size);

  return 0;
}

