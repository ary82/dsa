#include <string>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    int start{0};
    int length{1};

    for (int i{0}; i < s.size(); i++) {
      expand_from_center(s, i, i, start, length);
      expand_from_center(s, i, i + 1, start, length);
    }

    return s.substr(start, length);
  }

private:
  void expand_from_center(std::string &s, int left, int right, int &start,
                          int &length) {
    if (left < 0 || right > s.size() - 1 || s[left] != s[right]) {
      return;
    }

    if (right - left + 1 > length) {
      start = left;
      length = right - left + 1;
    }

    expand_from_center(s, left - 1, right + 1, start, length);
  }
};
