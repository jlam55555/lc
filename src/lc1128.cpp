class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    std::unordered_map<int, int> freqs;
    for (const auto &domino : dominoes) {
      auto i{std::min(domino[0], domino[1])}, j{std::max(domino[0], domino[1])};
      ++freqs[i * 9 + j];
    }

    auto res{0};
    for (const auto &[unused, freq] : freqs) {
      res += freq * (freq - 1) / 2;
    }

    return res;
  }
};
