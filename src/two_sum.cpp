#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<int> twoSumBruteForce(std::vector<int> &nums, int target) {
    std::vector<int> arr{-1, -1};
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          arr[0] = i;
          arr[1] = j;
        }
      }
    }
    return arr;
  }

  std::vector<int> twoSumHashMap(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    int n = map.size();
    for (int i = 0; i < n; i++) {
      int diff = target - nums[i];
      if (map.count(diff)) {
        return {map[diff], i};
      }
      map[nums[i]] = i;
    }
    return {-1, -1};
  }
};
