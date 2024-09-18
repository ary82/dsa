#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<std::vector<int>> result{};
    std::vector<int> ans{};

    dfs(candidates, result, ans, target, 0, 0);
    return result;
  }

private:
  void dfs(std::vector<int> &candidates, std::vector<std::vector<int>> &result,
           std::vector<int> &ans, int target, int sum, int iter) {
    if (sum == target) {
      result.push_back(ans);
      return;
    }

    if (sum > target) {
      return;
    }

    for (int i{iter}; i < candidates.size(); i++) {
      ans.push_back(candidates[i]);
      sum += candidates[i];
      dfs(candidates, result, ans, target, sum, i);
      sum -= candidates[i];
      ans.pop_back();
    }
  }
};
