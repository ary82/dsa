#include <climits>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  pacificAtlantic(std::vector<std::vector<int>> &heights) {

    int rows = heights.size();
    int cols = heights[0].size();
    std::vector<std::vector<int>> res{};

    std::vector<std::vector<bool>> pac(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<bool>> atl(rows, std::vector<bool>(cols, false));

    for (int r{0}; r < rows; r++) {
      dfs(heights, rows, cols, r, 0, pac, INT_MIN);
      dfs(heights, rows, cols, r, cols - 1, atl, INT_MIN);
    }

    for (int c{0}; c < cols; c++) {
      dfs(heights, rows, cols, 0, c, pac, INT_MIN);
      dfs(heights, rows, cols, rows - 1, c, atl, INT_MIN);
    }

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (pac[r][c] && atl[r][c]) {
          res.push_back({r, c});
        }
      }
    }
    return res;
  }

private:
  void dfs(std::vector<std::vector<int>> &heights, int rows, int cols, int r,
           int c, std::vector<std::vector<bool>> &ocean, int prev_height) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || ocean[r][c] ||
        heights[r][c] < prev_height) {
      return;
    }

    ocean[r][c] = true;

    dfs(heights, rows, cols, r + 1, c, ocean, heights[r][c]);
    dfs(heights, rows, cols, r - 1, c, ocean, heights[r][c]);
    dfs(heights, rows, cols, r, c + 1, ocean, heights[r][c]);
    dfs(heights, rows, cols, r, c - 1, ocean, heights[r][c]);
  }
};
