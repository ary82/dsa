#include <algorithm>
#include <stack>

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    values.push(val);

    if (minVal.empty()) {
      minVal.push(val);
    } else {
      minVal.push(std::min(val, minVal.top()));
    }
  }

  void pop() {
    if (!values.empty()) {
      values.pop();
      minVal.pop();
    }
  }

  int top() { return values.top(); }

  int getMin() { return minVal.top(); }

private:
  std::stack<int> values{};
  std::stack<int> minVal{};
};
