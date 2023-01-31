class WordDictionary {
  struct Node {
    bool is_word{};
    Node *children[26]{};
  };
  Node *root;

  bool search(const std::string_view word, int i, const Node *it) {
    if (!it) {
      return false;
    }

    if (i == word.length()) {
      return it->is_word;
    }

    if (word[i] != '.') {
      return search(word, i + 1, it->children[word[i] - 'a']);
    }

    for (int j{}; j < 26; ++j) {
      if (it->children[j] && search(word, i + 1, it->children[j])) {
        return true;
      }
    }
    return false;
  }

public:
  WordDictionary() : root{new Node} {}

  void addWord(string word) {
    auto it = root;
    for (char c : word) {
      auto &next = it->children[c - 'a'];
      if (!next) {
        next = new Node;
      }
      it = next;
    }
    it->is_word = true;
  }

  bool search(const std::string_view word) { return search(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
