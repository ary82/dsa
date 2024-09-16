#include <deque>
#include <vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int numOfIslands{};

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (grid[r][c] == '1') {
          bfs(grid, r, c, rows, cols);
          numOfIslands++;
        }
      }
    }

    return numOfIslands;
  }

private:
  void bfs(std::vector<std::vector<char>> &grid, int r, int c, int rows,
           int cols) {
    std::deque<std::pair<int, int>> q{};

    q.push_back({r, c});

    while (!q.empty()) {
      r = q.front().first;
      c = q.front().second;
      q.pop_front();

      if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
        continue;
      }

      grid[r][c] = '0';

      q.push_back({r + 1, c});
      q.push_back({r - 1, c});
      q.push_back({r, c + 1});
      q.push_back({r, c - 1});
    }
  }
};
