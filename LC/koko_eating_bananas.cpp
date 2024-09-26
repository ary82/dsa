#include <algorithm>
#include <vector>

class Solution {
public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    int l{1};
    int r = *std::max_element(piles.begin(), piles.end());
    int res{r};

    while (l <= r) {
      long int hours{0};
      int mid = (l + r) / 2;

      for (int pile : piles) {
        hours += pile / mid;
        if (pile % mid != 0) {
          hours += 1;
        }
      }

      if (hours > h) {
        l = mid + 1;
      } else {
        res = std::min(res, mid);
        r = mid - 1;
      }
    }

    return res;
  }
};
