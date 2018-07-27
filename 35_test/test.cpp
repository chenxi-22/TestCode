// #include <iostream>
// #include <stdio.h>
// 
// int main()
// {
//   std::cout<<"Filename"<<FILENAME_MAX<<std::endl;
//   std::cout<<"fopen"<<FOPEN_MAX<<std::endl;
// 
//   return 0;
// }
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
  int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  size_t a = 0;
  size_t b = 0;
  size_t c = 3;
  size_t d = 3;
  while (a < c && b < d) {
    size_t i = a;
    size_t j = b;
    for (; i < d; ++i) cout<<arr[j][i]<<" ";
    for (; j < c; ++j) cout<<arr[j][i]<<" ";
    for (; i > a; --i) cout<<arr[j][i]<<" ";
    for (; j > b; --j) cout<<arr[j][i]<<" ";
    a++, b++, c--, d--;
  }
}

// #include <iostream>
// #include <vector>
// 
// using namespace std;
// 
// class Solution {
// public:
//   vector<int> printMatrix(vector<vector<int> > matrix) {
//     size_t row = matrix.size();
//     size_t col = matrix[0].size();
//     vector<int> ret;
//     if (row == 0 || col == 0) return ret;
//     size_t a = 0;
//     size_t b = 0;
//     size_t c = row;
//     size_t d = col;
//     while (a < c) {
//       size_t i = a;
//       size_t j = b;
//       for (; i < d; ++i) ret.push_back(matrix[j][i]);
//       for (; j < c; ++j) ret.push_back(matrix[j][i]);
//       for (; i > a; --i) ret.push_back(matrix[j][i]);
//       for (; j > b; --j) ret.push_back(matrix[j][i]);
//       a++, b++, c--, d--;
//     }
//     return ret;
//   }
// };
// 
// int main()
// {
//   Solution s;
//   vector<vector<int> > arr;
// 
//   for (int i = 0; i < 4; ++i) {
//     for (int j = 0; j < 4; ++j) {
//       cin>>arr[i][j];
//     }
//   }
//  
//   s.printMatrix(arr);
//   return 0;
// }
// 
// 
// // int main()
// // {
// //   std::vector<std::vector<int> > arr;
// //   
// //   size_t row = arr.size();
// //   size_t col = arr[0].size();
// // }
// 
// 
