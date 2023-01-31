class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    std::vector<int> hist(26, INT_MAX);
    for (const auto &word : words) {
      std::vector<int> word_hist(26, 0);
      for (auto c : word) {
        ++word_hist[c - 'a'];
      }

      for (auto i{0}; i < 26; ++i) {
        hist[i] = std::min(hist[i], word_hist[i]);
      }
    }

    std::vector<std::string> res;
    for (auto i{0}; i < 26; ++i) {
      for (auto j{0}; j < hist[i]; ++j) {
        res.push_back(std::string(1, i + 'a'));
      }
    }
    return res;
  }
};
