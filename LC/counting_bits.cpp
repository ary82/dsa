#include <vector>

class Solution {
public:
  std::vector<int> countBits(int n) {
    std::vector<int> result;
    for (int i{0}; i <= n; i++) {
      int currentNum{0};
      int currentIter = i;
      while (currentIter) {
        currentIter = currentIter & (currentIter - 1);
        currentNum++;
      }
      result.push_back(currentNum);
    }
    return result;
  }
};
