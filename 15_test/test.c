#include <stdio.h>
#include <unistd.h>

int main()
{
  int n = 0;
  scanf("%d",&n);
  int arr[n];
  int sum = 0;
  int max = 0;
  int i = 0;

  for(; i < n; ++i) {
    scanf("%d ",&arr[i]);
  }

  for(i = 0; i < n; i++) {
    sum += arr[i];
    max = max > sum?max:sum;
  }
  printf("%d\n",max);

  return 0;
}


