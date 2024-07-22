struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    bool result{true};
    checkSubTree(p, q, result);
    return result;
  }

  void checkSubTree(TreeNode *p, TreeNode *q, bool &result) {
    if (p == nullptr && q == nullptr) {
      return;
    }

    if (p == nullptr || q == nullptr) {
      result = false;
      return;
    }

    if (p->val != q->val) {
      result = false;
    }

    checkSubTree(p->left, q->left, result);
    checkSubTree(p->right, q->right, result);
  }
};
