#include <climits>
#include <vector>

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
  bool isValidBST(TreeNode *root) { return recurse(root, LONG_MIN, LONG_MAX); }

private:
  bool recurse(TreeNode *node, long left, long right) {
    if (node == nullptr) {
      return true;
    }
    if (node->val <= left || node->val >= right) {
      return false;
    }

    return recurse(node->left, left, node->val) &&
           recurse(node->right, node->val, right);
  }
};

class Old_Solution {
public:
  bool isValidBST(TreeNode *root) {
    std::vector<int> list{};
    in_order(root, list);

    for (int i{0}; i < list.size(); i++) {
      if (i + 1 < list.size() && list[i] > list[i + 1]) {
        return false;
      }
    }
    return true;
  }

private:
  void in_order(TreeNode *node, std::vector<int> &list) {
    if (node == nullptr) {
      return;
    }
    in_order(node->left, list);
    list.push_back(node->val);
    in_order(node->right, list);
  }
};
