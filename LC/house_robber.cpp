#include <algorithm>
#include <vector>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    int prev1{0};
    int prev2{0};

    for (int num : nums) {
      int temp = std::max(prev2 + num, prev1);
      prev2 = prev1;
      prev1 = temp;
    }

    return prev1;
  }
};
