#include <iostream>
#include <vector>

using namespace std;

class Dynamic {
public:
  int CutRod(int n, vector<int> p) {
    if (n == 0) return 0;
    vector<int> value;
    value.push_back(0);
    for (int i = 1; i <= n; ++i) {
      int max_value = 0;
      for (int j = 1; j <= i; ++j) {
        max_value = max(max_value, p[j] + value[i - j]); // 最大价值的比较
      }
      value.push_back(max_value); // 存储每一个阶段的最大价值
    }
    return value[n];
  }
};

int main()
{
  vector<int> p;
  p.push_back(0);
  p.push_back(1);
  p.push_back(5);
  p.push_back(8);
  p.push_back(9);
  p.push_back(10);
  p.push_back(17);
  p.push_back(17);
  p.push_back(20);
  p.push_back(24);
  p.push_back(30);
  int n = 0;
  cin>>n;

  Dynamic dy;
  int max_value = dy.CutRod(n, p);
  cout<<max_value<<endl;

  return 0;
}
