// 1.给你一个数 N, 最少需要多少步把它变成斐波那契数
// #include <iostream>
// #include <vector>
// 
// using namespace std;
// 
// class Test {
// public:
//   int FibonacciCount(int n) {
//     if (n < 0) return -1;
//     if (n == 0 || n == 1 || n == 2) return 0;
//     vector<int> v;
//     v.push_back(0);
//     v.push_back(1);
//     int i = 2;
//     int tmp = 0;
//     while (1) {
//       tmp = v[i - 1] + v[i - 2];
//       v.push_back(tmp);
//       if (tmp > n) {
//         break;
//       }
//       i++;
//     }
//     i = v.size() - 1;
//     for (int j = 0; j < i + 1; ++j) {
//       cout<<v[j]<<" ";
//     }
//     cout<<endl;
// 
//     cout<<v[i]<<" "<<v[i - 1]<<endl;
//     int count = (v[i] - n) > (n - v[i - 1]) ? n - v[i - 1] : v[i] - n; 
//     return count;
//   }
// };
// 
// int main()
// {
//   Test t;
//   int n = 0;
//   cin>>n;
//   int ret = t.FibonacciCount(n);
//   cout<<ret<<endl;
//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// 
// class Test 
// {
// public:
//   bool InputisOK = true;
//   int FindArraySumMax(vector<int> input)
//   {
//     size_t size = input.size();
//     if (size < 0) {
//       InputisOK = false;
//       return 0;
//     }
//     InputisOK = true;
// 
//     int sum = 0;
//     int final_sum = -1111111111;
//     size_t i = 0;
//     while (i < size) {
//       if (sum < 0) sum = input[i];
//       else sum += input[i];
//       if (sum > final_sum) final_sum = sum;
//       i++;
//     }
//     return final_sum;
//   }
// };
// 
// int main()
// {
//   vector<int> input;
//   input.push_back(-1);
//   input.push_back(1);
//   input.push_back(7);
//   input.push_back(-15);
//   input.push_back(2);
//   std::vector<int>::iterator it = input.begin();
//   for (; it < input.end(); ++it) {
//     cout<<*it<<" ";
//   }
//   cout<<endl;
//   Test t;
//   int ret = t.FindArraySumMax(input);
//   cout<<ret<<endl;
// 
//   return 0;
// }

// #include <iostream>
// #include <string>
// 
// using namespace std;
// 
// // abccb
// class Test
// {
// public:
//   bool StrIsReverseTure(string s)
//   {
//     size_t size = s.size();
//     if (size <= 0) return false;
//     size_t left = 0;
//     size_t right = size - 1;
//     int flag = 0;
//     while (left < right) {
//       if (s[left] != s[right]) {
//         if (flag == 1) {
//           return false;
//         }
//         if (s[left+1] == s[right]) {
//           left++;
//           flag = 1;
//         } else if(s[left] == s[right-1]){
//           right--;
//           flag = 1;
//         } else {
//           return false;
//         }
//       }
//       left++, right--;
//     }
//     return true;
//   }
// };
// 
// int main()
// {
//   string s;
//   s += "abcdeddfddsacba";
//   // cout<<s.c_str()<<endl;
//   Test t;
//   bool ret = t.StrIsReverseTure(s);
//   if (ret) cout<<"is Reverse"<<endl;
//   else cout<<"is not Reverse"<<endl;
//   return 0;
// }
