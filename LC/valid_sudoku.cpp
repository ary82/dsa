#include <unordered_set>
#include <vector>
class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {

    for (int i{0}; i < 9; i++) {
      std::unordered_set<char> line{};
      std::unordered_set<char> col{};

      // line check
      for (int j{0}; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        }
        if (line.count(board[i][j])) {
          return false;
        }
        line.insert(board[i][j]);
      }

      // col check
      for (int j{0}; j < 9; j++) {
        if (board[j][i] == '.') {
          continue;
        }
        if (col.count(board[j][i])) {
          return false;
        }
        col.insert(board[j][i]);
      }
    }

    // grid check
    for (int i{0}; i < 9; i += 3) {
      for (int j{0}; j < 9; j += 3) {
        std::unordered_set<char> box{};

        for (int k{0}; k < 3; k++) {
          for (int l{0}; l < 3; l++) {
            if (board[i + k][j + l] == '.') {
              continue;
            }
            if (box.count(board[i + k][j + l])) {
              return false;
            }
            box.insert(board[i + k][j + l]);
          }
        }
      }
    }
    return true;
  }
};
