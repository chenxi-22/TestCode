#include <stdio.h>

void FindArray(int s)
{
  int i = 2;
  int cur = 0;
  int arr[1024] = {0};

  for (; i < s; i++) {
    int sum = (i - 1)*i/2;
    int num = (s - sum) % i;
    if (num == 0) {
      arr[i] = (s - sum) / i;
      cur++;
    }
  }
  for (i = 0; i < 1024; i++) {
    int j = 0;
    for (; j < i; j++) {
      printf("%d ", arr[i] + i);
    }
    printf("\n");
  }
  return;
}

int main()
{
  int s = 0;

  printf("please enter S:\n");
  scanf("%d",&s);

  FindArray(s);

  return 0;
}

//
//
// #include <stdio.h>
// #include <math.h>
// 
// int MergeNum(int a , int b)
// {
//   int cur = b;
//   int count = 1;
//   while (1) {
//     if (cur < 10) {
//       break;
//     }
//     cur %= 10;
//     count++;
//   }
//   return a * pow(10,count + 1) + b;
// }
// 
// int main()
// {
//   int a = 0;
//   int b = 0;
//   scanf("%d%d",&a,&b);
// 
//   int ret = MergeNum(a,b);
//   printf("%d\n",ret);
// 
//   return 0;
// }
// 
