#include <cstring>
#include <string>
#include <vector>

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (board[r][c] == word[0]) {
          if (dfs(board, word, 0, r, c, rows, cols)) {
            return true;
          }
        }
      }
    }

    return false;
  }

private:
  bool dfs(std::vector<std::vector<char>> &board, std::string &required,
           int idx, int r, int c, int rows, int cols) {

    if (r < 0 || r > rows - 1 || c < 0 || c > cols - 1 ||
        required[idx] != board[r][c]) {
      return false;
    }

    if (idx == required.size() - 1) {
      return true;
    }

    board[r][c] = '#';

    if (dfs(board, required, idx + 1, r + 1, c, rows, cols) ||
        dfs(board, required, idx + 1, r - 1, c, rows, cols) ||
        dfs(board, required, idx + 1, r, c + 1, rows, cols) ||
        dfs(board, required, idx + 1, r, c - 1, rows, cols)) {
      return true;
    }

    board[r][c] = required[idx];
    return false;
  }
};

class Old_Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    int rows = board.size();
    int cols = board[0].size();

    std::string curr{};

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        dfs(board, word, curr, 0, r, c, rows, cols);
      }
    }
    printf("%s\n%s\n", word.c_str(), curr.c_str());

    if (std::strcmp(word.c_str(), curr.c_str()) == 0) {
      return true;
    }

    return false;
  }

private:
  void dfs(std::vector<std::vector<char>> &board, std::string &required,
           std::string &curr, int idx, int r, int c, int rows, int cols) {

    // checks
    if (r < 0 || r > rows - 1 || c < 0 || c > cols - 1 ||
        required[idx] != board[r][c]) {
      return;
    }

    curr[idx] = board[r][c];
    board[r][c] = '#';

    dfs(board, required, curr, idx + 1, r + 1, c, rows, cols);
    dfs(board, required, curr, idx + 1, r - 1, c, rows, cols);
    dfs(board, required, curr, idx + 1, r, c + 1, rows, cols);
    dfs(board, required, curr, idx + 1, r, c - 1, rows, cols);

    board[r][c] = required[idx];
  }
};
