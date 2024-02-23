#include <vector>
class Solution {
public:
  static int findMin(std::vector<int> &nums) {
    int min = nums[0];
    int left{0};
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + ((right - left) / 2);
      if (nums[mid] < min) {
        min = nums[mid];
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return min;
  }
};
