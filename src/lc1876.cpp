class Solution {
public:
  int countGoodSubstrings(string s) {
    int res{}, n(s.length());
    for (int i{}; i < n - 2; ++i) {
      res += s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2];
    }
    return res;
  }
};
