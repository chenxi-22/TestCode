#include <iostream>

using namespace std;

namespace test1 {
  int a = 10;
};

namespace test2 {
  int a = 10;
};

int main()
{
  int a = 0;
  cout<<a<<endl;

  return 0;
}

// using namespace std;
// 
// void Test(char* str)
// {
//   cout<<str<<endl;
// }
// 
// void Test(int x)
// {
//   cout<<x<<endl;
// }
// 
// int main()
// {
//   char* str = "hello cpp!";
//   int x = 100;
//   Test(str);
//   Test(x);
// 
//   return 0;
// }
// 
