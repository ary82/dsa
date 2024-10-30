#include <vector>

class Solution {
public:
  int uniquePaths(int m, int n) {
    std::vector<int> dp(n, 1);

    for (int i{0}; i < m - 1; i++) {
      for (int j{n - 2}; j >= 0; j++) {
        dp[j] = dp[j] + dp[j + 1];
      }
    }

    return dp[0];
  }
};

class Old_Solution {
public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for (int i{0}; i < n; i++) {
      dp[m - 1][i] = 1;
    }

    for (int i{0}; i < m - 1; i++) {
      dp[i][n - 1] = 1;
    }

    for (int r{m - 2}; r >= 0; r--) {
      for (int c{n - 2}; c >= 0; c--) {
        dp[r][c] = dp[r + 1][c] + dp[r][c + 1];
      }
    }

    return dp[0][0];
  }
};
