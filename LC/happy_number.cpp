#include <cstdio>
#include <set>

class Solution {
public:
  bool isHappy(int n) {
    std::set<int> visited{};
    int current_num{n};

    while (!visited.count(current_num)) {
      if (current_num == 1) {
        return true;
      }

      visited.insert(current_num);

      // update current_num
      int copy{current_num};
      current_num = 0;
      while (copy != 0) {
        int copy_current_num = copy % 10;
        current_num += copy_current_num * copy_current_num;
        copy /= 10;
      }
    }

    return false;
  }
};
