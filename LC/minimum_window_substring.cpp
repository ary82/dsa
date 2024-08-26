#include <climits>
#include <string>
#include <unordered_map>

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {

    // Looping variables
    int i{0}, j{0};

    // Checking variables
    std::unordered_map<char, int> iter_map;
    std::unordered_map<char, int> t_map;
    for (char c : t) {
      t_map[c] += 1;
    }
    int same_count{0};
    int target = t_map.size();

    // Answer variables
    int left{0};
    int ans_len{INT_MAX};

    while (j < s.size()) {
      iter_map[s[j]] += 1;
      if (iter_map[s[j]] == t_map[s[j]]) {
        same_count += 1;
      }

      while (same_count == target) {
        if (j - i + 1 < ans_len) {
          left = i;
          ans_len = j - i + 1;
        }

        if (iter_map[s[i]] == t_map[s[i]]) {
          same_count -= 1;
        }
        iter_map[s[i]]--;
        i += 1;
      }

      j += 1;
    }

    return ans_len == INT_MAX ? "" : s.substr(left, ans_len);
  }
};
