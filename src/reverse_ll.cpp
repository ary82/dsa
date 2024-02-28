class Solution {
public:
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *prev = nullptr;
    while (head->next != nullptr) {
      ListNode *f = head->next;
      head->next = prev;
      prev = head;

      head = f;
    }
    head->next = prev;
    return head;
  }
};
