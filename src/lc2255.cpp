class Solution {
public:
  int countPrefixes(vector<string> &words, string s) {
    int res{};
    for (const auto &word : words) {
      res += !s.find(word);
    }
    return res;
  }
};
