#include <vector>

class Solution {
public:
  void solve(std::vector<std::vector<char>> &board) {
    int rows = board.size();
    int columns = board[0].size();

    // first and last rows
    for (int c{0}; c < columns; c++) {
      dfs(board, rows, columns, 0, c);
      dfs(board, rows, columns, rows - 1, c);
    }
    // first and last cols
    for (int r{1}; r < rows - 1; r++) {
      dfs(board, rows, columns, r, 0);
      dfs(board, rows, columns, r, columns - 1);
    }

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < columns; c++) {
        if (board[r][c] == 'O') {
          board[r][c] = 'X';
        }
        if (board[r][c] == 'a') {
          board[r][c] = 'O';
        }
      }
    }
  }

private:
  void dfs(std::vector<std::vector<char>> &board, int rows, int columns, int r,
           int c) {
    if (r < 0 || r >= rows || c < 0 || c >= columns || board[r][c] != 'O') {
      return;
    }

    board[r][c] = 'a';
    dfs(board, rows, columns, r + 1, c);
    dfs(board, rows, columns, r - 1, c);
    dfs(board, rows, columns, r, c + 1);
    dfs(board, rows, columns, r, c - 1);
  }
};
