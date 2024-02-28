class Solution {
public:
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *newlist = new ListNode();
    ListNode *newlistRef = newlist;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        newlist->next = list1;
        list1 = list1->next;
      } else {
        newlist->next = list2;
        list2 = list2->next;
      }
      newlist = newlist->next;
    }

    if (list1) {
      newlist->next = list1;
    } else if (list2) {
      newlist->next = list2;
    }
    return newlistRef->next;
  }
};
