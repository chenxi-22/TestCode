#include <iostream>

typedef struct ListNode {
  int val;
  struct ListNode* next;
} ListNode;

class Test 
{
public:
  ListNode* FindKthToTail(ListNode* head, int k) {
    if (head == NULL) {
      return NULL;
    }
    int i = 0;
    ListNode* fast = head;
    ListNode* slow = head;
    for(; slow != NULL; ++i) {
      if (i >= k) {
        slow = slow->next;
      }
      fast = fast->next;
    }

    return slow == NULL ? NULL : slow;
  }
};

