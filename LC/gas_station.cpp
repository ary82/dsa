#include <vector>

class Solution {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int check{0};
    for (int i{0}; i < gas.size(); i++) {
      cost[i] = gas[i] - cost[i];
      check += cost[i];
    }
    if (check < 0) {
      return -1;
    }

    int total{0};
    int start{0};
    for (int i{0}; i < cost.size(); i++) {
      total += cost[i];
      if (total < 0) {
        total = 0;
        start = i + 1;
      }
    }
    return start;
  }
};
