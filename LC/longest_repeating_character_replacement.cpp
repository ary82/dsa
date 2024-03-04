#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  static int characterReplacement(std::string s, int k) {

    int left{0}, right{0}, max{0}, maxOfMap{0};
    std::unordered_map<char, int> map{};

    while (right < s.size()) {

      map[s[right]] += 1;
      maxOfMap = std::max(maxOfMap, map[s[right]]);

      while ((right - left + 1) - maxOfMap > k) {
        map[s[left]]--;
        left++;
      }

      right++;
      max = std::max(max, right - left);
    }
    return max;
  }
};
