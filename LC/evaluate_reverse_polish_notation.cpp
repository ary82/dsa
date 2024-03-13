#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> nums{};

    for (auto &i : tokens) {
      if (i == "+") {
        int first = nums.top();
        nums.pop();
        int second = nums.top();
        nums.pop();
        nums.push(second + first);
      } else if (i == "-") {
        int first = nums.top();
        nums.pop();
        int second = nums.top();
        nums.pop();
        nums.push(second - first);
      } else if (i == "/") {
        int first = nums.top();
        nums.pop();
        int second = nums.top();
        nums.pop();
        nums.push(second / first);
      } else if (i == "*") {
        int first = nums.top();
        nums.pop();
        int second = nums.top();
        nums.pop();
        nums.push(second * first);
      } else {
        nums.push(std::stoi(i));
      }
    }

    return nums.top();
  }
};
