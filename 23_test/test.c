// #include <stdio.h>
// #include <math.h>
// 
// int main()
// {
//   int x = 0;
//   int y = 0;
// 
//   printf("请输入一个数：");
//   scanf("%d",&x);
//   
//   if (x >= 0) {
//     y = pow(x, 3);
//   } else {
//     y = pow(x, 2);
//   }
//   printf("y = %d\n",y);
// 
//   return 0;
// }
// #include <stdio.h>
// 
// int main()
// {
//   int arr[30] = {0};
//   arr[0] = 1, arr[1] = 1, arr[2] = 2;
// 
//   int i = 0;
//   int j = 0;
//   int k = 0;
// 
//   for (j = 0; j < 5; ++j) {
//     for (k = 0; k < 6; ++k) {
//       if (i < 3) {
//         printf("%d ", arr[i]);
// 
//       } else {
//         arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
//         printf("%d ", arr[i]);
//       }
//       i++;
//     }
//     printf("\n");
//   }
// 
//   return 0;
// 
// }
//

#include <stdio.h>

int main()
{
  char ch = 'a';
  printf("%c\n", ch - ('a' - 'A'));

  return 0;
}
