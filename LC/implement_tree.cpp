#include <string>

class TrieNode {
public:
  TrieNode *children[26];
  bool isEndOfWord;

  TrieNode() {
    for (int i{0}; i < 26; i++) {
      children[i] = nullptr;
    }
    isEndOfWord = false;
  }

  TrieNode(char letter) {
    for (int i{0}; i < 26; i++) {
      children[i] = nullptr;
    }
    isEndOfWord = false;
  }
};

class Trie {
public:
  Trie() { root = new TrieNode(); }

  void insert(std::string word) {
    TrieNode *head = root;

    for (char i : word) {
      if (head->children[i - 'a'] == nullptr) {
        head->children[i - 'a'] = new TrieNode();
      }
      head = head->children[i - 'a'];
    }

    head->isEndOfWord = true;
  }

  bool search(std::string word) {
    TrieNode *head = root;

    for (char i : word) {
      if (head->children[i - 'a'] == nullptr) {
        return false;
      }
      head = head->children[i - 'a'];
    }

    return head->isEndOfWord;
  }

  bool startsWith(std::string prefix) {
    TrieNode *head = root;

    for (char i : prefix) {
      if (head->children[i - 'a'] == nullptr) {
        return false;
      }
      head = head->children[i - 'a'];
    }

    return true;
  }

private:
  TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
