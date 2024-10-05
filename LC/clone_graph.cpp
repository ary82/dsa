#include <deque>
#include <unordered_map>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }

    std::unordered_map<Node *, Node *> old_to_new{};

    Node *newRoot = new Node(node->val);
    old_to_new[node] = newRoot;

    std::deque<Node *> q{node};

    while (!q.empty()) {
      Node *top = q.front();
      q.pop_front();

      for (Node *i : top->neighbors) {
        if (old_to_new.find(i) == old_to_new.end()) {
          old_to_new[i] = new Node(i->val);
          q.push_back(i);
        }
        old_to_new[top]->neighbors.push_back(old_to_new[i]);
      }
    }

    return newRoot;
  }
};
