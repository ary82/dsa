#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int max{0};
    int size = s.size();
    if (size == 0 || size == 1) {
      return size;
    }

    int p1{0}, p2{0};
    std::unordered_set<char> chars;

    while (p2 < size) {
      while (chars.count(s[p2])) {
        chars.erase(s[p1]);
        p1++;
      }
      chars.insert(s[p2]);
      p2++;
      max = std::max(max, p2 - p1);
    }
    return max;
  }
};
