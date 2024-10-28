#include <climits>
#include <stack>
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
  int kthSmallest(TreeNode *root, int k) {
    int ans{};
    inorder(root, k, ans);
    return ans;
  }

private:
  void inorder(TreeNode *node, int &k, int &ans) {
    if (node == nullptr) {
      return;
    }

    inorder(node->left, k, ans);
    k -= 1;
    if (k == 0) {
      ans = node->val;
      return;
    }
    inorder(node->right, k, ans);
  }
};

class Iter_Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    std::vector<int> sorted{};
    std::stack<TreeNode *> inorder{};
    TreeNode *curr = root;

    while (curr != nullptr || !inorder.empty()) {

      while (curr != nullptr) {
        inorder.push(curr);
        curr = curr->left;
      }

      TreeNode *top = inorder.top();
      inorder.pop();
      sorted.push_back(top->val);

      if (sorted.size() == k) {
        break;
      }

      curr = curr->right;
    }

    return sorted.back();
  }
};
