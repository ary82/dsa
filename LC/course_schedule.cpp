#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::unordered_map<int, std::vector<int>> prereqs_map{};

    for (std::vector<int> &prereq : prerequisites) {
      prereqs_map[prereq[0]].push_back(prereq[1]);
    }

    std::unordered_set<int> visited{};

    for (int i{0}; i < numCourses; i++) {
      if (!dfs(prereqs_map, visited, i)) {
        return false;
      }
    }

    return true;
  }

private:
  bool dfs(std::unordered_map<int, std::vector<int>> &prereq_map,
           std::unordered_set<int> &visited, int course) {
    if (visited.find(course) != visited.end()) {
      return false;
    }
    if (prereq_map[course].empty()) {
      return true;
    }

    visited.insert(course);

    for (int prereq : prereq_map[course]) {
      if (!dfs(prereq_map, visited, prereq)) {
        return false;
      }
    }

    visited.erase(course);
    prereq_map[course].clear();
    return true;
  }
};
