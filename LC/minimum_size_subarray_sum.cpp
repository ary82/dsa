#include <climits>
#include <vector>

class Solution {
public:
  int minSubArrayLen(int target, std::vector<int> &nums) {

    int i{0}, j{0};
    int curr_sum{0};
    int ans = INT_MAX;

    while (j <= nums.size() - 1) {
      curr_sum += nums[j];

      while (curr_sum >= target) {
        ans = std::min(j - i + 1, ans);
        curr_sum -= nums[i];
        i += 1;
      }
      j += 1;
    }

    if (ans == INT_MAX) {
      ans = 0;
    }
    return ans;
  }
};
