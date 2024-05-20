#include <algorithm>
#include <vector>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int water{0};

    int left{0};
    int right = height.size() - 1;
    int maxL = height[left];
    int maxR = height[right];

    while (left < right) {
      if (maxL < maxR) {
        left += 1;
        maxL = std::max(height[left], maxL);
        water += maxL - height[left];

      } else {
        right -= 1;
        maxR = std::max(height[right], maxR);
        water += maxR - height[right];
      }
    }
    return water;
  }
};
