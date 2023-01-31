class Trie {
public:
  struct Node {
    bool is_word_{false};
    Node *children_[26]{nullptr};

    // Reference counting for deletion.
    // This can be removed if deletion is not
    // necessary.
    int rc_{};
  };

  // Adds a word to the trie. Returns false if the word
  // already exists. The check can be removed if not needed.
  bool AddWord(const string &word) {
    auto it = root_;
    // Not necessary but technically correct. Keeps track
    // of how many words there are in the trie.
    ++it->rc_;
    for (auto c : word) {
      auto &next = it->children_[c - 'a'];
      if (!next) {
        next = new Node;
      }
      ++next->rc_;
      it = next;
    }
    if (it->is_word_) {
      // Shouldn't happen.
      throw logic_error{"addition found existing word"};
    }
    it->is_word_ = true;
    return true;
  }

  // Delete a word from the trie. Returns false if the word
  // doesn't exist in the trie. The check can be removed if not
  // needed.
  bool RemoveWord(const string &word) {
    auto it = root_;
    // Not necessary but technically correct. See the note in
    // AddWord().
    --it->rc_;
    for (auto c : word) {
      auto &next = it->children_[c - 'a'];
      if (!next || !next->rc_) {
        // Shouldn't happen.
        throw logic_error{"deleted node on deletion path"};
      }
      --next->rc_;
      it = next;
    }
    if (!it->is_word_) {
      // Shouldn't happen.
      throw logic_error{"deletion found non-word"};
    }
    it->is_word_ = false;
    return true;
  }

  // Get root.
  Node *Root() const { return root_; }

private:
  Node *root_{new Node};
};

class Solution {
public:
  // State for the dfs.
  vector<vector<bool>> seen_;
  vector<vector<char>> b_;
  int h_;
  int w_;
  Trie t_{};
  Trie::Node *tn_{t_.Root()};
  vector<string> result_{};
  string word_{};

  void dfs(int i, int j) {
    if (i < 0 || i >= h_ || j < 0 || j >= w_ // out of bounds
        || seen_[i][j]                       // already visited this cell
        || !tn_->rc_                         // node deleted
        || !tn_->children_[b_[i][j] - 'a']   // next node not defined
    ) {
      return;
    }
    auto prev_node = tn_;

    // Push to state.
    seen_[i][j] = true;
    word_.push_back(b_[i][j]);
    tn_ = tn_->children_[b_[i][j] - 'a'];

    // If it is a word:
    // - Add word to results vector.
    // - Remove from the trie to avoid re-looking for this and
    //   avoid duplicates in the results vector.
    if (tn_->is_word_) {
      result_.push_back(word_);
      t_.RemoveWord(word_);
    }

    // Recurse.
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);

    // Pop from state.
    seen_[i][j] = false;
    word_.pop_back();
    tn_ = prev_node;
  }

  vector<string> findWords(vector<vector<char>> &board,
                           const vector<string> &words) {
    b_ = std::move(board);

    // Edge case.
    if (!b_.size()) {
      return {};
    }

    // Add all the words to a trie.
    for (auto &word : words) {
      t_.AddWord(word);
    }

    // Perform a dfs from each cell using the trie.
    h_ = b_.size();
    w_ = b_[0].size();
    seen_ = vector(h_, vector(w_, false));
    for (auto i = 0; i < h_; ++i) {
      for (auto j = 0; j < w_; ++j) {
        ;
        dfs(i, j);
      }
    }

    return result_;
  }
};
