#include <iostream>
#include <stack>
#include <string>
class Solution {
public:
  static bool isValid(std::string s) {
    std::stack<char> buff;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        buff.push((s[i]));
      } else if ((buff.size() == 0) || (buff.top() != '(' && s[i] == ')') ||
                 (buff.top() != '{' && s[i] == '}') ||
                 (buff.top() != '[' && s[i] == ']')) {
        return false;
      } else {
        buff.pop();
      }
    }
    return buff.empty();
  };
};
