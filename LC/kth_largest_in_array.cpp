#include <queue>
#include <vector>

class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    k = nums.size() - k;
    return quickSelect(nums, 0, nums.size() - 1, k);
  }

  int quickSelect(std::vector<int> &nums, int k, int left, int right) {
    int pivot = nums[right];
    int p = left;

    for (int i = left; i < right; ++i) {
      if (nums[i] <= pivot) {
        std::swap(nums[p], nums[i]);
        p++;
      }
    }
    std::swap(nums[p], nums[right]);

    if (p > k) {
      return quickSelect(nums, k, left, p - 1);
    } else if (p < k) {
      return quickSelect(nums, k, p + 1, right);
    } else {
      return nums[p];
    }
  }
};
class HeapSolution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue<int> pq{};
    for (int i : nums) {
      pq.push(i);
    }
    while (--k) {
      pq.pop();
    }

    return pq.top();
  }
};
