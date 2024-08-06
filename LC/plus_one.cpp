#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {

    int size = digits.size() - 1;
    digits[size] += 1;
    int current_ele{size};

    while (digits[current_ele] > 9) {
      digits[current_ele] = 0;
      if (current_ele == 0) {
        digits.insert(digits.begin(), 1);
        break;
      }
      digits[current_ele - 1] += 1;
      current_ele -= 1;
    }

    return digits;
  }
};
