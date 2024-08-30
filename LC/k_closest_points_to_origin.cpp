#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                         int k) {

    std::vector<std::vector<int>> ans;
    std::priority_queue<std::pair<int, int>> pq;

    for (int i{0}; i < points.size(); i++) {
      pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    while (k--) {
      ans.push_back(points[pq.top().second]);
      pq.pop();
    }

    return ans;
  }
};
