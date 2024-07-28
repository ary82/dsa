#include <queue>
#include <vector>

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {
public:
  KthLargest(int k, std::vector<int> &nums) {
    this->k = k;
    for (int i{0}; i < nums.size(); i++) {
      pq.push(nums[i]);
    }

    while (pq.size() > k) {
      pq.pop();
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > k) {
      pq.pop();
    }

    return pq.top();
  }

private:
  int k;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};
