#include <string>
#include <unordered_map>

class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {

    if (s1.size() > s2.size()) {
      return false;
    }

    // Variable declarations
    int start{0};
    int end = s1.size() - 1;
    std::unordered_map<char, int> freqMap;
    std::unordered_map<char, int> movingMap;

    // Make initial maps
    for (char i : s1) {
      freqMap[i]++;
    }
    for (int i{0}; i <= end; i++) {
      movingMap[s2[i]]++;
    }

    while (end < s2.size()) {

      bool found = true;
      for (auto i : freqMap) {
        if (movingMap[i.first] != i.second) {
          found = false;
        }
      }
      if (found) {
        return true;
      }

      movingMap[s2[end + 1]]++;
      movingMap[s2[start]]--;
      start++;
      end++;
    }
    return false;
  }
};
