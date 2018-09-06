#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// binare_tree
struct TreeNode {
  int _val;
  TreeNode* _lchild;
  TreeNode* _rchild;
};

class BinaryTree {
public:
  void pre_order() {
    if (_root == nullptr)
      return;

    stack<TreeNode*> s;
    s.push(_root);
    while (!s.empty()) {
      TreeNode* top = s.top();
      // visit
      cout << top->_val << endl;
      s.pop();
      if (top->_rchild)
        s.push(top->_rchild);
      if (top->_lchild)
        s.push(top->_lchild);
    }
  }

  void in_order() {
    if (_root == nullptr)
      return;

    stack<TreeNode*> s;
    s.push(_root);
    TreeNode* cur = _root->_lchild;
    while (!s.empty()) {
      while (cur) {
        s.push(cur);
        cur = cur->_lchild;
      }
      TreeNode* top = s.top();
      s.pop();
      // visit
      cout << top->_val << endl;
      cur = top->_rchild;
    }
  }

  void post_order() {
    if (_root == nullptr)
      return;

    stack<TreeNode*> s;
    s.push(_root);
    TreeNode* cur = _root->_lchild;
    TreeNode* pre = nullptr;
    while (!s.empty()) {
      while (cur) {
        s.push(cur);
        cur = cur->_lchild;
      }
      TreeNode* top = s.top();
      if (top->_rchild == nullptr || top->_rchild == pre) { // visit
        cout << top->_val << endl;
        s.pop();
        pre = top;
      }
      cur = top->_rchild;
    }
  }

  void level_order() {
    if (_root == nullptr)
      return;

    queue<TreeNode*> q;
    q.push(_root);
    while (!q.empty()) {
      TreeNode* front = q.front();
      q.pop();
      // visit
      cout << front->_val << endl;
      if (front->_lchild)
        q.push(front->_lchild);
      if (front->_rchild)
        q.push(front->_rchild);
    }
  }
private:
  TreeNode* _root;
};

// sort
class Sort {
public:
  Sort(vector<int> v) 
    :_v(v) {}

  void bubble_sort() {
    for (size_t i = 0; i < _v.size(); ++i) {
      for (size_t j = 0; j < _v.size() - i; ++j) {
        if (_v[i] < _v[j]) 
          swap(_v[i], _v[j]);
      }
    }
  }

  void select_sort() {
    for (size_t i = 0; i < _v.size(); ++i) {
      for (size_t j = i + 1; j < _v.size(); ++j) {
        if (_v[i] > _v[j])
          swap(_v[i], _v[j]);
      }
    }
  }

  void insert_sort() {
    for (size_t bound = 1; bound < _v.size(); ++bound) {
      size_t cur = bound - 1;
      int tmp = _v[bound];
      while (cur >= 0 && _v[cur] > tmp) {
        _v[cur + 1] = _v[cur];
        --cur;
      }
      _v[cur + 1] = tmp;
    }
  }

  void shell_sort() {
    size_t gap = _v.size() / 2;
    for (; gap > 0; --gap) {
      for (size_t i = 0; i > gap; ++i) {
        for (size_t bound = i + gap; bound < _v.size(); bound += gap) {
          int tmp = _v[bound];
          size_t cur = bound - gap;
          while (cur >= 0 && _v[cur] > tmp) {
            _v[cur + gap] = _v[cur];
            cur -= gap;
          }
          _v[cur + gap] = tmp;
        }
      }
    }
  }

  void adjust_down(size_t parent, size_t size)  {
    size_t child = 2 * parent + 1;
    while (child < size) {
      if (child + 1 < size && _v[child + 1] > _v[child])
        child += 1;
      if (_v[parent] < _v[child]) {
        swap(_v[parent], _v[child]);
        parent = child;
        child = 2 * parent + 1;
      } else {
        break;
      }
    }
  }

  void heap_sort() {
    size_t parent = _v.size() / 2 - 1;
    for (; parent >= 0; --parent) 
      adjust_down(parent, _v.size());
    for (size_t i = 0; i < _v.size(); ++i) {
      size_t bound = _v.size() - i;
      swap(_v[0], _v[bound - 1]);
      adjust_down(0, bound - 1);
    }
  }

  void _merge_array(size_t beg, size_t mid, size_t end, int* tmp) {
    size_t cur1 = beg;
    size_t cur2 = mid;
    size_t index = beg;
    while (cur1 < mid && cur2 < end) {
      if (_v[cur1] < _v[cur2])
        tmp[index++] = _v[cur1++];
      else
        tmp[index++] = _v[cur2++];
    }
    while (cur1 < mid) 
      tmp[index++] = _v[cur1++];
    while (cur2 < end) 
      tmp[index++] = _v[cur2++];

    while (beg < end) {
      _v[beg] = tmp[beg];
      ++beg;
    }
  }

  void _merge_sort(size_t beg, size_t end, int* tmp) {
    if (tmp == nullptr)
      return;
    if (beg >= end - 1)
      return;

    size_t mid = beg + (end - beg) / 2;
    _merge_sort(beg, mid, tmp);
    _merge_sort(mid, end, tmp);
    _merge_array(beg, mid, end, tmp);
  }

  void merge_sort() {
    int* tmp = new int[_v.size()];
    size_t beg = 0;
    size_t end = _v.size();
    _merge_sort(beg, end, tmp);
    delete[] tmp;
  }

  size_t exchange_val(size_t beg, size_t end) {
    end -= 1;
    size_t index = end; 
    int key = _v[index];
    while (beg < end) {
      while (beg < end && _v[beg] <= key) 
        ++beg;
      while (beg < end && _v[end] >= key) 
        --end;
      if (beg < end) 
        swap(_v[beg], _v[end]);
    }
    swap(_v[index], _v[beg]);
    return beg;
  }

  void _quick_sort(size_t beg, size_t end) {
    if (beg >= end)
      return;

    size_t mid = exchange_val(beg, end);
    _quick_sort(beg, mid);
    _quick_sort(mid + 1, end);
  }

  void quick_sort() {
    size_t beg = 0;
    size_t mid = _v.size();
    _quick_sort(beg, mid);
  }

private:
  vector<int> _v;
};

