class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    bool allowed_map[26]{};
    for (auto c : allowed) {
      allowed_map[c - 'a'] = 1;
    }
    int res{};
    for (const auto &word : words) {
      for (int c : word) {
        if (!allowed_map[c - 'a']) {
          goto outer;
        }
      }
      ++res;
    outer:;
    }
    return res;
  }
};
