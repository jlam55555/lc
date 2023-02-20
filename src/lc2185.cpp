class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int res{};
    for (const auto &word : words) {
      res += !word.find(pref);
    }
    return res;
  }
};
