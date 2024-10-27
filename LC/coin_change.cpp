#include <algorithm>
#include <vector>

class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i{1}; i < amount + 1; i++) {
      for (int coin : coins) {
        if (i - coin >= 0) {
          dp[i] = std::min(dp[i], 1 + dp[i - coin]);
        }
      }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
