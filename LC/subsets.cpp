#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {

    std::vector<std::vector<int>> result{};
    std::vector<int> ans{};

    dfs(nums, ans, 0, result);
    return result;
  }

private:
  void dfs(std::vector<int> &nums, std::vector<int> &ans, int i,
           std::vector<std::vector<int>> &result) {
    if (i == nums.size()) {
      result.push_back(ans);
      return;
    }

    ans.push_back(nums[i]);
    dfs(nums, ans, i + 1, result);

    ans.pop_back();
    dfs(nums, ans, i + 1, result);
  }
};
