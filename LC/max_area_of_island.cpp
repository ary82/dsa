#include <vector>

class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int area{0};

    for (int i{0}; i < rows; i++) {
      for (int j{0}; j < cols; j++) {
        if (grid[i][j] == 1) {
          int local_area{0};
          dfs(grid, rows, cols, i, j, area, local_area);
        }
      }
    }

    return area;
  }

private:
  void dfs(std::vector<std::vector<int>> &grid, int rows, int cols, int r,
           int c, int &area, int &local_area) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
      return;
    }

    grid[r][c] = 0;
    local_area += 1;

    if (local_area >= area) {
      area = local_area;
    }

    dfs(grid, rows, cols, r + 1, c, area, local_area);
    dfs(grid, rows, cols, r - 1, c, area, local_area);
    dfs(grid, rows, cols, r, c + 1, area, local_area);
    dfs(grid, rows, cols, r, c - 1, area, local_area);
  }
};
