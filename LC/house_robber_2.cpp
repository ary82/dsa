#include <algorithm>
#include <vector>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    int size = nums.size();
    if (size == 1) {
      return nums[0];
    }
    return std::max(rob_line(nums, 0, size - 1), rob_line(nums, 1, size));
  }

private:
  int rob_line(std::vector<int> &nums, int start, int end) {
    int prev1{0};
    int prev2{0};

    for (int i{start}; i < end; i++) {
      int temp = std::max(prev2 + nums[i], prev1);
      prev2 = prev1;
      prev1 = temp;
    }
    return prev1;
  }
};
