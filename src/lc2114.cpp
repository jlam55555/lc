class Solution {
public:
  int mostWordsFound(vector<string> &sentences) {
    int res{};
    for (const auto &sentence : sentences) {
      int spaces{};
      for (auto c : sentence) {
        spaces += c == ' ';
      }
      res = std::max(res, spaces);
    }
    return res + 1;
  }
};
