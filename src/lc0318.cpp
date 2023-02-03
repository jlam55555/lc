class Solution {
public:
  int maxProduct(vector<string> &words) {
    int N(words.size());
    std::vector<int> letters(N, 0);
    for (int i{}; i < N; ++i) {
      for (auto c : words[i]) {
        letters[i] |= (1u << (c - 'a'));
      }
    }

    int res{};
    for (int i{}; i < N; ++i) {
      for (int j{i + 1}; j < N; ++j) {
        if (!(letters[i] & letters[j])) {
          res = std::max(res, int(words[i].length() * words[j].length()));
        }
      }
    }
    return res;
  }
};
