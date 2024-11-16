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
  int goodNodes(TreeNode *root) { return dfs(root, root->val); }

private:
  int dfs(TreeNode *node, int highest) {
    if (node == nullptr) {
      return 0;
    }

    int res{node->val >= highest ? 1 : 0};
    highest = std::max(highest, node->val);
    res += dfs(node->left, highest);
    res += dfs(node->right, highest);
    return res;
  }
};
