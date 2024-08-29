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
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::queue<TreeNode *> lo_queue{};
    std::vector<std::vector<int>> ans{};

    if (root == nullptr) {
      return ans;
    }

    lo_queue.push(root);

    while (!lo_queue.empty()) {
      int current_level_count = lo_queue.size();
      std::vector<int> vector_curr_level{};

      while (current_level_count > 0) {
        TreeNode *iter = lo_queue.front();
        lo_queue.pop();
        vector_curr_level.push_back(iter->val);

        if (iter->left != nullptr) {
          lo_queue.push(iter->left);
        }
        if (iter->right != nullptr) {
          lo_queue.push(iter->right);
        }
        current_level_count -= 1;
      }
      ans.push_back(vector_curr_level);
    }

    return ans;
  }
};
