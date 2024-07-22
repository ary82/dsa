#include <cstdio>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *secondHalf = reverseList(slow->next);
    slow->next = nullptr;
    ListNode *firstHalf = head;

    while (secondHalf != nullptr) {
      ListNode *tmp1 = firstHalf->next;
      ListNode *tmp2 = secondHalf->next;

      firstHalf->next = secondHalf;
      secondHalf->next = tmp1;

      firstHalf = tmp1;
      secondHalf = tmp2;
    }
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *current = head;
    ListNode *prev = nullptr;
    while (current != nullptr) {
      ListNode *next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
};
