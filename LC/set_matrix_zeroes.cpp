#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool rowZero{false};

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (matrix[r][c] == 0) {
          // mark col to be zero
          matrix[0][c] = 0;
          // mark row to be zero
          r == 0 ? rowZero = true : matrix[r][0] = 0;
        }
      }
    }
    for (int r{1}; r < rows; r++) {
      for (int c{1}; c < cols; c++) {
        if (matrix[0][c] == 0 || matrix[r][0] == 0) {
          matrix[r][c] = 0;
        }
      }
    }
    if (matrix[0][0] == 0) {
      for (int r{0}; r < rows; r++) {
        matrix[r][0] = 0;
      }
    }

    if (rowZero) {
      for (int c{0}; c < cols; c++) {
        matrix[0][c] = 0;
      }
    }
  }
};

class Old_Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<bool> rows_to_be_zero(rows, false);
    std::vector<bool> cols_to_be_zero(cols, false);

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (matrix[r][c] == 0) {
          rows_to_be_zero[r] = true;
          cols_to_be_zero[c] = true;
        }
      }
    }

    for (int r{0}; r < rows; r++) {
      if (rows_to_be_zero[r]) {
        for (int &i : matrix[r]) {
          i = 0;
        }
      }
    }
    for (int c{0}; c < cols; c++) {
      if (cols_to_be_zero[c]) {
        for (int r{0}; r < rows; r++) {
          matrix[r][c] = 0;
        }
      }
    }
  }
};
