#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {

    std::vector<std::vector<int>> result{};
    std::vector<int> ans{};
    std::sort(nums.begin(), nums.end());

    dfs(nums, ans, 0, result);
    return result;
  }

private:
  void dfs(std::vector<int> &nums, std::vector<int> &ans, int i,
           std::vector<std::vector<int>> &res) {
    if (i == nums.size()) {
      res.push_back(ans);
      return;
    }

    ans.push_back(nums[i]);
    dfs(nums, ans, i + 1, res);

    ans.pop_back();

    int temp{0};
    while (i + temp < nums.size() && nums[i + temp] == nums[i]) {
      temp += 1;
    }
    dfs(nums, ans, i + temp, res);
  }
};
