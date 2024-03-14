class Solution {
public:
  int getSum(int a, int b) {
    while (b != 0) {
      int carryOver = a & b;
      a = a ^ b;
      b = carryOver << 1;
    }
    return a;
  }
};
