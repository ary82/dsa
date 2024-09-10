#include <vector>

class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {
    int n = cost.size();

    for (int i{3}; i <= n; i++) {
      cost[n - i] += std::min(cost[n - i + 1], cost[n - i + 2]);
    }

    return std::min(cost[0], cost[1]);
  }
};
