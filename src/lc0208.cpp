class Trie {
  struct Node {
    int count = 0;
    Node *children[26] = {0};
  };
  Node *root;

  int wordCount(string word) {
    Node *tn = root;
    for (char c : word) {
      if (!tn->children[c - 'a'])
        return -1;
      tn = tn->children[c - 'a'];
    }
    return tn->count;
  }

public:
  /** Initialize your data structure here. */
  Trie() { root = new Node{}; }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node *tn = root;
    for (char c : word) {
      if (!tn->children[c - 'a'])
        tn->children[c - 'a'] = new Node{0};
      tn = tn->children[c - 'a'];
    }
    ++tn->count;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) { return wordCount(word) > 0; }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) { return wordCount(prefix) != -1; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
