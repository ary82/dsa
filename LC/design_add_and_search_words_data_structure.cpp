#include <string>

class TrieNode {
public:
  TrieNode *children[26];
  bool is_end_of_word;
  TrieNode() {
    for (int i{0}; i < 26; i++) {
      children[i] = nullptr;
    }
    is_end_of_word = false;
  };
};

class WordDictionary {
public:
  WordDictionary() { root = new TrieNode(); }

  void addWord(std::string word) {
    TrieNode *head = root;

    for (char c : word) {
      if (head->children[c - 'a'] == nullptr) {
        head->children[c - 'a'] = new TrieNode();
      }
      head = head->children[c - 'a'];
    }

    head->is_end_of_word = true;
  }

  bool search(std::string word) {
    TrieNode *head = root;

    return dfs(word, 0, head);
  }

private:
  TrieNode *root;

  bool dfs(std::string word, int i, TrieNode *head) {
    if (head == nullptr) {
      return false;
    }

    if (i == word.size()) {
      return head->is_end_of_word;
    }

    if (word[i] != '.') {
      return dfs(word, i + 1, head->children[word[i] - 'a']);
    }

    for (int j{0}; j < 26; j++) {
      if (dfs(word, i + 1, head->children[j])) {
        return true;
      }
    }

    return false;
  }
};
