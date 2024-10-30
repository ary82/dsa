#include <algorithm>
#include <vector>

class Solution {
public:
  void wallsAndGates(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (grid[r][c] == 0) {
          dfs(grid, rows, cols, r, c, 0);
        }
      }
    }

    return;
  }

private:
  void dfs(std::vector<std::vector<int>> &grid, int rows, int cols, int r,
           int c, int distance) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == -1 ||
        distance > grid[r][c]) {
      return;
    }

    grid[r][c] = std::min(grid[r][c], distance);

    dfs(grid, rows, cols, r + 1, c, distance + 1);
    dfs(grid, rows, cols, r - 1, c, distance + 1);
    dfs(grid, rows, cols, r, c + 1, distance + 1);
    dfs(grid, rows, cols, r, c - 1, distance + 1);
  }
};
