#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  // Hashmap
  static std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::set<std::vector<int>> Ans_set;
    int size = nums.size();

    // Sort the input array
    std::sort(nums.begin(), nums.end());

    // Nums Iterate
    for (int i{0}; i < size; i++) {
      // Select One Element and create map
      int target = -nums[i];
      std::unordered_map<int, int> map;

      // Iterate over remaining Elements
      for (int j = i + 1; j < size; j++) {
        int diff = target - nums[j];

        if (map.count(diff)) {
          std::vector<int> data{nums[i], nums[j], diff};
          Ans_set.insert((data));
        }
        map[nums[j]] = j;
      }
    }
    std::vector<std::vector<int>> Answer;
    for (auto i : Ans_set) {
      Answer.push_back(i);
    }
    return Answer;
  }

  // Two Pointer
  static std::vector<std::vector<int>> threeSumII(std::vector<int> &nums) {
    int size = nums.size();
    std::vector<std::vector<int>> Answer;

    // Sort the input array
    std::sort(nums.begin(), nums.end());

    for (int i{0}; i < size; i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left{i + 1};
      int right{size - 1};

      while (left < right) {
        if (nums[right] < 0) {
          break;
        }
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) {
          left++;
        } else if (sum > 0) {
          right--;
        } else {
          Answer.push_back({nums[i], nums[left], nums[right]});
          left++;

          while (nums[left] == nums[left - 1] && left < right) {
            left++;
          }
          while (nums[right] == nums[right - 1] && left < right) {
            right--;
          }
        }
      }
    }
    return Answer;
  }
};
