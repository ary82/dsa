#include <algorithm>
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
  int diameterOfBinaryTree(TreeNode *root) {
    int result{0};
    dfs(root, result);
    return result;
  }

  int dfs(TreeNode *root, int &result) {
    if (root == nullptr) {
      return 0;
    }
    int left = dfs(root->left, result);
    int right = dfs(root->right, result);
    int temp = std::max(result, left + right);
    result = temp;

    return 1 + std::max(left, right);
  }
};
