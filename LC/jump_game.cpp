#include <vector>

class Solution_prev {
public:
  bool canJump(std::vector<int> &nums) {
    for (int i{0}; i < nums.size(); i++) {
      if (nums[i] == 0) {
        for (int j{i}; j >= 0; j--) {
          if (nums[j] > i - j || (nums[j] == i - j) && i == nums.size() - 1) {
            break;
          }
          if (j == 0) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int curr{0};
    for (int i{0}; i < nums.size(); i++) {
      curr = std::max(curr - 1, nums[i]);
      if (curr == 0 && i < nums.size() - 1) {
        return false;
      }
    }
    return true;
  }
};
