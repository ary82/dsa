#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return nullptr;
    }

    while (lists.size() > 1) {
      std::vector<ListNode *> temp;

      for (int i{0}; i < lists.size(); i += 2) {
        ListNode *l1 = lists[i];
        ListNode *l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
        temp.push_back(merge2Lists(l1, l2));
      }
      lists = temp;
    }

    return lists[0];
  }

private:
  ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
    // both are null
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    }

    ListNode *d = new ListNode();
    ListNode *curr = d;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        curr->next = l1;
        curr = curr->next;
        l1 = l1->next;

      } else {
        curr->next = l2;
        curr = curr->next;
        l2 = l2->next;
      }
    }

    if (l1 == nullptr) {
      curr->next = l2;
    } else {
      curr->next = l1;
    }

    return d->next;
  }
};
