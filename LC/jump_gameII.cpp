#include <algorithm>
#include <vector>

class Solution {
public:
  int jump(std::vector<int> &nums) {
    int jumps{0};
    int left{0};
    int right{0};

    while (right < nums.size() - 1) {
      int max{0};
      for (int i{left}; i <= right; i++) {
        max = std::max(max, nums[i] + i);
      }

      left = right + 1;
      right = max;
      jumps += 1;
    }

    return jumps;
  }
};
