#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    int l{0};
    int r = nums.size() - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      // left of mid is sorted
      if (nums[mid] >= nums[l]) {
        if (target > nums[mid] || target < nums[l]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
        // right of mid is sorted
      } else {
        if (target < nums[mid] || target > nums[r]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }

    return -1;
  }
};
