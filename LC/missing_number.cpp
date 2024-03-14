#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int sum = (nums.size() * (nums.size() - 1)) / 2;
    for (int i : nums) {
      sum -= i;
    }
    return sum;
  }
};
