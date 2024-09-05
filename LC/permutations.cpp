#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result{};
    std::vector<int> ans{};
    std::unordered_set<int> set{};

    dfs(nums, ans, result, set);
    return result;
  }

private:
  void dfs(std::vector<int> &nums, std::vector<int> &ans,
           std::vector<std::vector<int>> &result, std::unordered_set<int> set) {
    if (ans.size() == nums.size()) {
      result.push_back(ans);
      return;
    }

    for (int i{0}; i < nums.size(); i++) {
      if (set.count(nums[i]) != 0) {
        continue;
      }
      set.insert(nums[i]);
      ans.push_back(nums[i]);
      dfs(nums, ans, result, set);
      ans.pop_back();
      set.erase(nums[i]);
    }
  }
};
