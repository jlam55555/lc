class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    std::array<int, 26> freqs{};
    for (auto c : chars) {
      ++freqs[c - 'a'];
    }

    int res{};
    for (const auto &word : words) {
      auto f{freqs};
      for (auto c : word) {
        if (!f[c - 'a']--) {
          goto bad;
        }
      }
      res += word.length();
    bad:;
    }
    return res;
  }
};
