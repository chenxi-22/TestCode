#include <stdio.h>

#define N 4

void rotate(int arr[N][N], int a, int b, int c, int d)
{
  int i = 0;
  for(; i < d - b; ++i) {
    int tmp = arr[a][b + i];
    arr[a][b+i] = arr[c - i][b];
    arr[c - i][b] = arr[c][d - i];
    arr[c][d - i] = arr[a + i][d];
    arr[a + i][d] = tmp;
  }
}

void show(int arr[N][N])
{
  int i = 0;
  int j = 0;
  for (; i < N; ++i) {
    for (j = 0; j < N; ++j) {
      printf("%2d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int arr[N][N] = {
    1,1,1,0,
    0,0,1,1,
    1,1,0,0,
    0,0,0,1,
  };
}

int main1()
{
  int arr[N][N];
  int num = 1;

  int i = 0; 
  int j = 0;
  for (; i < N; ++i) {
    for (j = 0; j < N; ++j) {
      arr[i][j] = num++;
    }
  }
  show(arr);
  rotate(arr, 0, 0, N - 1, N - 1);
  show(arr);

  return 0;
}
