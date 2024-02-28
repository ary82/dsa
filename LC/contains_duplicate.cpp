#include <unordered_map>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_map<int, int> map{};
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (map[nums[i]] == 1) {
        return true;
      }
      map[nums[i]]++;
    }
    return false;
  }
};
