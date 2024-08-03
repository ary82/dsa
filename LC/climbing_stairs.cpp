class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }

    int current{2}, previous{1};

    for (int i{2}; i < n; i++) {
      int tmp = current;
      current = current + previous;
      previous = tmp;
    }

    return current;
  }
};
