#include <climits>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int curr{nums[0]};
    int result{nums[0]};

    for (int i{0}; i < nums.size(); i++) {
      curr = std::max(curr + nums[i], nums[i]);
      result = std::max(result, curr);
    }

    return result;
  }
};
