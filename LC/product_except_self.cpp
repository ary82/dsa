#include <vector>

class Solution {
public:
  static std::vector<int> productExceptSelf(std::vector<int> &nums) {

    std::vector<int> solution_array{};

    int product{1};
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      solution_array.push_back(product);
      product *= nums[i];
    }
    product = 1;
    for (int i = size - 1; i >= 0; i--) {
      solution_array[i] *= product;
      product *= nums[i];
    }
    return solution_array;
  }
};
