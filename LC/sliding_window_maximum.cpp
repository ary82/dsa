#include <deque>
#include <vector>

class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    int size = nums.size();
    std::vector<int> res(size - k + 1);
    std::deque<int> deq;

    int l{0};
    int r{0};

    while (r < size) {
      while (!deq.empty() && nums[deq.back()] < nums[r]) {
        deq.pop_back();
      }
      deq.push_back(r);

      if (l > deq[0]) {
        deq.pop_front();
      }

      if (r + 1 >= k) {
        res[l] = (nums[deq.front()]);
        l += 1;
      }
      r += 1;
    }

    return res;
  }
};
