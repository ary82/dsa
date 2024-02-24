#include <vector>

class Solution {
public:
  static std::vector<int> twoSum(std::vector<int> &numbers, int target) {

    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum < target) {
        left++;
      } else if (sum > target) {
        right--;
      } else {
        return {left + 1, right + 1};
      }
    }
    return {};
  }
};
