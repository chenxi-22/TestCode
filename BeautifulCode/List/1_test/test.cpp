#include <iostream>

typedef struct ListNode {
  int val;
  struct ListNode* next;
} ListNode;

class Test {
public:
  ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2) {
    if (head1 == NULL || head2 == NULL) {
      return NULL;
    }

    ListNode* cur1 = head1;
    ListNode* cur2 = head2;
    
    while (cur1 != cur2) {
      cur1 = (cur1 == NULL ? head2 : cur1->next);
      cur2 = (cur2 == NULL ? head1 : cur2->next);
    }

    return cur1;
  }
};

