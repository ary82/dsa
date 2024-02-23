#include <algorithm>
#include <vector>
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int left{0};
    int right{1};
    int len = prices.size();
    int maxprof{0};

    while (right < len) {
      int diff = prices[right] - prices[left];
      if (diff > maxprof) {
        maxprof = diff;
      } else if (diff < 0) {
        right++;
        continue;
      } else {
        left = right;
      }
      right++;
    }
    return maxprof;
  }

  int maxProfit2(std::vector<int> &prices) {
    int left{0};
    int right{1};
    int maxprof{0};

    while (right < prices.size()) {
      int diff = prices[right] - prices[left];
      if (diff > 0) {
        maxprof = std::max(diff, maxprof);
      } else {
        left = right;
      }
      right++;
    }
    return maxprof;
  }
};
