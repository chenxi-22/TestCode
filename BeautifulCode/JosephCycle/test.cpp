#include <iostream>
#include <vector>

using namespace std;

class Test
{
public:
  int JosephCycle(int n , int m) {
    vector<int> arr;
    int i = n;
    while (i--) {
      arr.push_back(1);
    }

    int count = n; // 剩余人数
    int step = 0; // 步数
    while (count > 0) {
      i++;
      if (i >= n) {
        i = 0;
      }
      if (arr[i] == 2) { // 当 arr[i] == 2 的时候，意味着此时 i 这个位置的人已经死了
        continue;
      }
      step++;
      if (step == m) {
        step = 0;
        count--;
        arr[i] = 2;
      }
    }
    return i; // 死的最后一个人就是生存者
  }
};

int main()
{
  Test t;
  int ret = t.JosephCycle(6, 3);
  cout<<ret<<endl;
  return 0;
}
