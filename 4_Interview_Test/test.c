#include <stdio.h>

//定义规则，找到返回1，没找到返回0，错误返回-1
int FindDataInArr(int (*arr)[4], int to_find)
{
  if(arr == NULL) {
    return -1;
  }
  int row = 0;
  int col = 3;
  while(row < 4 && col >= 0) {
    if(arr[row][col] == to_find) {
      return 1;
    } else if(arr[row][col] < to_find) {
      row++;
    } else {
      col--;
    }
  }
  return 0;
}

int main()
{
  int arr[4][4] = {
    {1, 2, 8,  9},
    {2, 4, 9,  12},
    {4, 7, 10, 13},
    {6, 8, 11, 15}
  };

  int to_find = 0;
  printf("please enter you want to find->");
  scanf("%d",&to_find);

  int ret = FindDataInArr(arr, to_find);
  printf("ret expected 1, ret actual %d\n",ret);
  return 0;
}

