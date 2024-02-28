#include <string>
#include <unordered_map>

class Solution {
public:
  static bool isAnagram(std::string &s, std::string &t) {
    int s_len = s.size();
    int t_len = t.size();
    std::unordered_map<char, int> map;

    for (int i = 0; i < s_len; i++) {
      map[s[i]]++;
    }
    for (int i = 0; i < t_len; i++) {
      map[t[i]]--;
    }

    for (auto &i : map) {
      if (i.second != 0) {
        return false;
      }
    }
    return true;
  }
};
