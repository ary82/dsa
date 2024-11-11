#include <unordered_set>
#include <vector>

class Solution {
public:
  bool validTree(int n, std::vector<std::vector<int>> &edges) {
    std::vector<std::unordered_set<int>> adjacency_list(n);
    for (auto edge : edges) {
      adjacency_list[edge[0]].insert(edge[1]);
      adjacency_list[edge[1]].insert(edge[0]);
    }
    std::unordered_set<int> visited{};
    return dfs(adjacency_list, visited, 0, -1) && visited.size() == n;
  }

private:
  bool dfs(std::vector<std::unordered_set<int>> &adj_list,
           std::unordered_set<int> &visited, int node, int prevNode) {
    if (visited.find(node) != visited.end()) {
      return false;
    }
    visited.insert(node);

    for (auto neighbour : adj_list[node]) {
      if (neighbour == prevNode) {
        continue;
      }
      if (!dfs(adj_list, visited, neighbour, node)) {
        return false;
      }
    }
    return true;
  }
};
