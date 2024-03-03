#include <algorithm>
#include <vector>

class Solution {
public:
  static int maxArea(std::vector<int> &height) {
    int left{0}, maxArea{0};
    int right = height.size() - 1;

    while (right >= left) {
      int currentArea = (right - left) * std::min(height[left], height[right]);
      maxArea = std::max(maxArea, currentArea);

      if (height[left] > height[right]) {
        right--;
      } else {
        left++;
      }
    }
    return maxArea;
  }
};
