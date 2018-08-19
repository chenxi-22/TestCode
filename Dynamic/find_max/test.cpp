#include <iostream>
#include <vector>
using namespace std;

class FindArrayMaxSum {
public:
  int FindMax(vector<int> arr)
  {
    vector<int> max;
    int size = arr.size();

    for (int i = 0; i < size; ++i) {
      if (i == 0) {
        max.push_back(arr[i]);
        continue;
      }

      if (max[i - 1] < 0) {
        max.push_back(arr[i]);
      } else {
        int tmp = max[i - 1] > max[i - 1] + arr[i] ? max[i - 1] : max[i - 1] + arr[i];
        cout<<arr[i]<<" "<<max[i - 1]<<endl;
        max.push_back(tmp);
      }
    }
    for (int i = 0; i < size; ++i) {
      cout<<max[i]<<" ";
    }
    cout<<endl;
    return max[size - 1];
  }
};

int main()
{
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(4);
  arr.push_back(-2);
  arr.push_back(-7);
  arr.push_back(15);
  FindArrayMaxSum f;
  int ret = f.FindMax(arr);
  cout<<ret<<endl;

  return 0;
}
