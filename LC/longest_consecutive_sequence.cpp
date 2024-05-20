#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {

    std::unordered_set<int> s(nums.begin(), nums.end());
    int best{0};

    for (int i : s) {
      if (!s.count(i - 1)) {
        int local_best{0};
        while (s.count(i + local_best)) {
          local_best += 1;
          best = std::max(best, local_best);
        }
      }
    }

    return best;
  }
};
