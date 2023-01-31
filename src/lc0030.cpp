// Note: This solution isn't very fast. But it is relatively
// straightforward using a trie data structure (implementation copied
// from jlam55555/dsa).

class Trie {
public:
  struct Node {
    bool is_word{false};
    Node *children[26]{nullptr};

    // Reference counting for deletion.
    // This can be removed if deletion is not
    // necessary.
    int rc{0};
  };

  // Adds a word to the trie. Returns false if the word
  // already exists.
  bool AddWord(const std::string &word);

  // Delete a word from the trie. Returns false if the word
  // doesn't exist in the trie.
  bool RemoveWord(const std::string &word);

  // Checks if a word exists in the trie.
  bool HasWord(const std::string &word) const;

  // Get root.
  Node *Root() const { return root_; }

private:
  Node *root_{new Node};
};

bool Trie::AddWord(const std::string &word) {
  if (HasWord(word)) {
    return false;
  }

  auto it{root_};
  // Not necessary but technically correct. Keeps track
  // of how many words there are in the trie.
  ++it->rc;
  for (auto c : word) {
    auto &next{it->children[c - 'a']};
    if (!next) {
      next = new Node;
    }
    ++next->rc;
    it = next;
  }
  if (it->is_word) {
    // Shouldn't happen.
    // TODO: Remove exceptions to be Google style guide compliant.
    throw std::logic_error{"addition found existing word"};
  }
  it->is_word = true;
  return true;
}

bool Trie::RemoveWord(const std::string &word) {
  if (!HasWord(word)) {
    return false;
  }

  auto it{root_};
  // Not necessary but technically correct. See the note in
  // AddWord().
  --it->rc;
  for (auto c : word) {
    auto &next{it->children[c - 'a']};
    if (!next || !next->rc) {
      // Shouldn't happen.
      // TODO: Remove exceptions to be Google style guide compliant.
      throw std::logic_error{"deleted node on deletion path"};
    }
    --next->rc;
    it = next;
  }
  if (!it->is_word) {
    // Shouldn't happen.
    // TODO: Remove exceptions to be Google style guide compliant.
    throw std::logic_error{"deletion found non-word"};
  }
  it->is_word = false;
  return true;
}

bool Trie::HasWord(const std::string &word) const {
  auto it{root_};
  for (auto c : word) {
    auto &next{it->children[c - 'a']};
    if (!next || !next->rc) {
      return false;
    }
    it = next;
  }
  return it->is_word;
}

class Solution {
public:
  vector<int> findSubstring(const string_view s, const vector<string> &words) {
    // Probably a dynamic programming problem.
    // Want to store all possible words that begin at any particular location.
    // Use this to your advantage.

    // Probably want to build a trie of words to efficiently store the words.
    Trie t{};
    auto total_len{0};
    for (const auto &word : words) {
      t.AddWord(word);
      total_len += word.length();
    }

    // From each letter, get the words that start there.
    // wsap == words_starting_at_pos
    std::vector<std::vector<std::string>> wsap(s.length());
    for (auto i{0}; i < s.length(); ++i) {
      auto it{t.Root()};
      std::string word{""};
      for (auto j{i}; j < s.length(); ++j) {
        word.push_back(s[j]);
        it = it->children[s[j] - 'a'];
        if (!it) {
          break;
        }
        if (it->is_word) {
          wsap[i].push_back(word);
          // std::cout << "word beginning at " << i << ": " << word <<
          // std::endl;
        }
      }
    }

    // From each starting position, DFS out and see if we hit all the words.
    std::vector<int> res{};
    std::unordered_map<std::string, int> remaining{};
    for (const auto &word : words) {
      ++remaining[word];
    }
    for (auto i{0}; i < s.length() - total_len + 1; ++i) {
      auto remaining_copy(remaining);
      if (Dfs(i, wsap, remaining_copy, words.size())) {
        res.push_back(i);
      }
    }

    return res;
  }

private:
  bool Dfs(const int i, const std::vector<std::vector<std::string>> &wsap,
           std::unordered_map<std::string, int> &remaining,
           int remaining_count) {

    // std::cout << "i=" << i << ": " << std::endl;
    // for (const auto& it : remaining) {
    //     std::cout << it.first << "=" << it.second << " ";
    // }
    // std::cout << std::endl;

    if (!remaining_count--) {
      return true;
    }

    // Will probably need to memoize this.
    // Starting at position i, can we fill the remaining words?
    for (const auto &j : wsap[i]) {
      if (!remaining[j]) {
        continue;
      }

      --remaining[j];
      // Short circuit once we've found something.
      if (Dfs(i + j.length(), wsap, remaining, remaining_count)) {
        return true;
      }
      ++remaining[j];
    }

    return false;
  }
};
