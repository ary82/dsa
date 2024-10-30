#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res{};
    dfs(res, "", n, 0, 0);

    return res;
  }

private:
  void dfs(std::vector<std::string> &res, std::string curr, int n, int open,
           int close) {
    if (open == n && close == n) {
      res.push_back(curr);
      return;
    }

    if (open > close) {
      dfs(res, curr + ')', n, open, close + 1);
    }

    if (open < n) {
      dfs(res, curr + '(', n, open + 1, close);
    }
  }
};
