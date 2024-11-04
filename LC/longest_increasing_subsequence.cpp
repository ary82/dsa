#include <algorithm>
#include <vector>

class Solution {
public:
  int lengthOfLIS(std::vector<int> &nums) {
    int size = nums.size();
    std::vector<int> dp(size, 1);

    for (int i{size - 1}; i >= 0; i--) {
      for (int j{i + 1}; j < size; j++) {
        if (nums[i] < nums[j]) {
          dp[i] = std::max(dp[i], 1 + dp[j]);
        }
      }
    }

    return *std::max_element(dp.begin(), dp.end());
  }
};
