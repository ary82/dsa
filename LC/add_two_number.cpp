struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *new_head = new ListNode();
    ListNode *ref = new_head;

    int carry_over{0};
    while (l1 || l2 || carry_over != 0) {
      int cur_num{0};
      if (l1 && l2) {
        cur_num = l1->val + l2->val + carry_over;
        (l1) ? l1 = l1->next : l1 = nullptr;
        (l2) ? l2 = l2->next : l2 = nullptr;
      } else if (l2 != nullptr) {
        cur_num = l2->val + carry_over;
        (l2) ? l2 = l2->next : l2 = nullptr;
      } else if (l1 != nullptr) {
        cur_num = l1->val + carry_over;
        (l1) ? l1 = l1->next : l1 = nullptr;
      } else {
        cur_num = carry_over;
      }

      carry_over = cur_num / 10;
      cur_num = cur_num % 10;

      ListNode *node = new ListNode(cur_num);
      ref->next = node;
      ref = ref->next;
    }
    return new_head->next;
  }
};
