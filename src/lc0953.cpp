class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    int map[26];
    for (auto i{0}; i < 26; ++i) {
      map[order[i] - 'a'] = i + 'a';
    }

    std::string prev_word;
    for (auto &word : words) {
      for (auto &c : word) {
        c = map[c - 'a'];
      }
      if (!prev_word.empty() && prev_word > word) {
        return false;
      }
      prev_word = word;
    }
    return true;
  }
};
