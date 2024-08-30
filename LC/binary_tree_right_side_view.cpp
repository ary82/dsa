#include <queue>
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
  std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> ans{};
    if (root == nullptr) {
      return ans;
    }

    std::queue<TreeNode *> bt_queue{};
    bt_queue.push(root);

    while (!bt_queue.empty()) {
      ans.push_back(bt_queue.back()->val);
      int curr_level_size = bt_queue.size();

      while (curr_level_size > 0) {
        TreeNode *iter = bt_queue.front();
        bt_queue.pop();

        if (iter->left != nullptr) {
          bt_queue.push(iter->left);
        }

        if (iter->right != nullptr) {
          bt_queue.push(iter->right);
        }

        curr_level_size -= 1;
      }
    }

    return ans;
  }
};
