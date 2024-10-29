#include <string>

class Solution {
public:
  int countSubstrings(std::string s) {
    int num{0};

    for (int i{0}; i < s.size(); i++) {
      expand_from_center(s, i, i, num);
      expand_from_center(s, i, i + 1, num);
    }

    return num;
  }

private:
  void expand_from_center(std::string &s, int left, int right, int &num) {
    if (left < 0 || right > s.size() - 1 || s[left] != s[right]) {
      return;
    }
    num += 1;
    expand_from_center(s, left - 1, right + 1, num);
  }
};
