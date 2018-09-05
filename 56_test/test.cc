#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
  int _val;
  struct TreeNode* _lchild;
  struct TreeNode* _rchild;
};

class BinaryTree {
public:
  typedef TreeNode Node;

public:
  void level_order() {                 // 层序遍历: 首先将根节点入队列，接着取队首元素，并出队列;
    if (_root == nullptr)              //           接着如果队首元素左子树不为空，入左子树，右子树
      return;                          //           右子树不为空，入右子树。直至队列为空，退出即可;
    queue<Node*> q;
    q.push(_root);
    while (!q.empty()) {
      Node* front = q.front();
      q.pop();
      // visit
      cout << front->_val << endl;
      if (front->_lchild != nullptr)
        q.push(front->_lchild);
      if (front->_rchild != nullptr) 
        q.push(front->_rchild);
    }
  }

  /* 先序遍历: 利用栈来实现先序遍历; 首先将根节点入栈，接着取栈顶元素，
   *           出栈，访问栈顶元素。如果栈顶元素右子树不为空，入右子树，
   *           左子树不为空，入左子树; 依次循环，直至栈为空，退出; */
  void pre_order() {
    if (_root == nullptr)
      return;
    stack<Node*> s;
    s.push(_root);
    while (!s.empty()) {
      Node* top = s.top();
      s.pop();
      // visit
      cout << top->_val << endl;
      if (top->_rchild != nullptr)
        s.push(top->_rchild);
      if (top->_lchild != nullptr)
        s.push(top->_lchild);
    }
  }

  /* 中序遍历: 利用一个栈，首先定义个节点等于根节点，将该节点入栈。进入循环，
   *           将该节点所有左子树入栈，直至左子树为空，此时取栈顶，访问，出
   *           栈; 接着让该节点等于栈顶的右子树，继续循环。直至栈空，退出。*/
  void in_order() {
    if (_root == nullptr)
      return;
    Node* cur = _root;
    stack<Node*> s;
    s.push(cur);
    cur = cur->_lchild;
    while (!s.empty()) {
      while (cur != nullptr) {
        s.push(cur->_lchild);
        cur = cur->_lchild;
      }
      Node* top = s.top();
      s.pop();
      // visit
      cout << top->_val << endl;
      cur = top->_rchild;
    }
  }

  /* 后序遍历: 利用一个栈，首先将根节点入栈，创建一个新的节点来保存
   *           上一个访问的元素。创建新的节点保存根节点的左子树，循
   *           环入栈新节点的左子树。直至左子树为空，此时取栈顶，并
   *           判断是否能够访问该节点。
   *           判断的依据是: a.该节点右子树为空 
   *                         b.上一个访问的节点是该节点的右子树
   *           如果能够访问，则访问，并且设置该节点为上一个访问的元
   *           素，如果无法访问，那么新节点等于该节点的右子树，继续
   *           入栈。直至栈为空，退出。*/
  void post_order() {
    if (_root == nullptr)
      return;
    stack<Node*> s;
    s.push(_root);
    Node* cur = _root->_lchild;
    Node* pre = nullptr;
    while (!s.empty()) {
      while (cur != nullptr) {
        s.push(cur);
        cur = cur->_lchild;
      }
      Node* top = s.top();
      if (top->_rchild == nullptr || top->_rchild == pre) {
        s.pop();
        cout << top->_val << endl;
        pre = top;
      }
      cur = top->_rchild;
    }
  }

private:
  Node* _root;
};

typedef TreeNode Node;
void pre_order(Node* root) {
  if (root == nullptr)
    return;

  stack<Node*> s;
  s.push(root);
  while (!s.empty()) {
    Node* top = s.top();
    s.pop();
    cout << top->_val << endl;
    if (top->_rchild)
      s.push(top->_rchild);
    if (top->_lchild)
      s.push(top->_lchild);
  }
}

void in_order(Node* root) {
  if (root == nullptr)
    return;

  stack<Node*> s;
  s.push(root);
  Node* cur = root->_lchild;
  while (!s.empty()) {
    while (cur) {
      s.push(cur);
      cur = cur->_lchild;
    }
    Node* top = s.top();
    s.pop();
    cout << top->_val << endl;
    cur = top->_rchild;
  }
}

void post_order(Node* root) {
  if (root == nullptr)
    return;

  stack<Node*> s;
  s.push(root);
  Node* cur = root->_lchild;
  Node* pre = nullptr;
  while (!s.empty()) {
    while (cur) {
      s.push(cur);
      cur = cur->_lchild;
    }
    Node* top = s.top();
    if (top->_rchild == nullptr || top->_rchild == pre) {
      cout << top->_val;
      s.pop();
      pre = top;
    }
    cur = top->_rchild;
  }
}

