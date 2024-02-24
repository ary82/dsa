#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {

    std::unordered_map<int, int> map{};
    std::vector<int> Answer{};

    for (int i : nums) {
      map[i] += 1;
    }

    for (int i{0}; i<k; i++) {
      int max{0};
      int ele;

      for (auto &i : map) {
        if (i.second > max) {
          max = i.second;
          ele = i.first;
        }
      }
      map.erase(ele);
      Answer.push_back(ele);
    }

    return Answer;
  }
};
