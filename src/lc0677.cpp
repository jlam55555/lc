// Classic trie problem.
class MapSum {
  struct Node {
    Node *children[26]{};
    int val{}, word_val{};
  };

  Node root_{};

public:
  void insert(std::string_view key, int val) {
    auto *it{&root_};

    // First pass to see if we need to override.
    // Also create nodes along the way.
    for (char c : key) {
      auto *&next{it->children[c - 'a']};
      if (!next) {
        next = new Node;
      }
      it = next;
    }
    auto update_val{it->word_val ? val - it->word_val : val};

    // Update/insert value.
    it = &root_;
    for (char c : key) {
      (it = it->children[c - 'a'])->val += update_val;
    }
    it->word_val = val;
  }

  int sum(std::string_view prefix) {
    auto *it{&root_};
    for (char c : prefix) {
      auto *next{it->children[c - 'a']};
      if (!next) {
        return {};
      }
      it = next;
    }
    return it->val;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
