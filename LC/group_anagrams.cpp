#include <string>
#include <vector>
class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {

    std::vector<std::vector<std::string>> answer;
    unordered_map<std::string, std::vector<string>> map;

    for (auto &i : strs) {
      map[getIdentifier(i)].push_back(i);
    }
    for (auto &i : map) {
      answer.push_back(i.second);
    }
    return answer;
  }

private:
  std::string getIdentifier(std::string &s) {
    int ident[26] = {0};
    for (char &i : s) {
      ident[i - 'a'] += 1;
    }

    std::string identifier;
    for (int i{0}; i < 26; i++) {
      identifier.append(std::to_string(ident[i]) + '.');
    }
    return identifier;
  }
};
