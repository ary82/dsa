#include <array>
#include <deque>
#include <vector>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>> &grid) {
    int rows{static_cast<int>(grid.size())};
    int cols{static_cast<int>(grid[0].size())};

    int fresh{0};
    int time{0};
    std::deque<std::pair<int, int>> q;

    for (int r{0}; r < rows; r++) {
      for (int c{0}; c < cols; c++) {
        if (grid[r][c] == 1) {
          fresh += 1;
        }
        if (grid[r][c] == 2) {
          q.push_back({r, c});
        }
      }
    }

    while (!q.empty() && fresh != 0) {
      int curr_queue_size{static_cast<int>(q.size())};

      for (int i{0}; i < curr_queue_size; i++) {
        std::pair rotten = q.front();
        q.pop_front();

        for (std::pair dir : directions) {
          int x = rotten.first + dir.first;
          int y = rotten.second + dir.second;

          if (x < rows && y < cols && x >= 0 && y >= 0 && grid[x][y] == 1) {
            grid[x][y] = 2;
            fresh -= 1;
            q.push_back({x, y});
          }
        }
      }
      time += 1;
    }

    if (fresh == 0) {
      return time;
    } else {
      return -1;
    }
  }

private:
  std::array<std::pair<int, int>, 4> directions{
      std::make_pair(1, 0), {-1, 0}, {0, 1}, {0, -1}};
};
