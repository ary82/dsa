#include <vector>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    // mxn matrix
    int m = matrix[0].size();
    int n = matrix.size();

    int left{0};
    int right{m * n - 1};
    while (left <= right) {
      int mid = left + ((right - left) / 2);

      if (matrix[mid / m][mid % m] < target) {
        left = mid + 1;
      } else if (matrix[mid / m][mid % m] > target) {
        right = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
