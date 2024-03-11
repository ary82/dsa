#include <utility>
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
  TreeNode *invertTree(TreeNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    std::swap(node->left, node->right);
    invertTree(node->left);
    invertTree(node->right);
    return node;
  }
};
