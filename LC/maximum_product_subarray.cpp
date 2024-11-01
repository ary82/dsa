#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    int res{INT_MIN};
    int currMax{1};
    int currMin{1};

    for (int n : nums) {
      int tmp{currMax};
      currMax = std::max({currMax * n, currMin * n, n});
      currMin = std::min({tmp * n, currMin * n, n});

      res = std::max(res, currMax);
    }
    return res;
  }
};
