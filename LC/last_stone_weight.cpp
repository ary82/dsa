#include <queue>
#include <vector>

class Solution {
public:
  int lastStoneWeight(std::vector<int> &stones) {

    std::priority_queue<int> pq;
    for (int i : stones) {
      pq.push(i);
    }

    while (pq.size() > 1) {
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();

      if (x - y > 0) {
        pq.push(x - y);
      }
    }

    if (pq.size() == 0) {
      return 0;
    }
    return pq.top();
  }
};
