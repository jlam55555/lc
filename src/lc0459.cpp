class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    for (auto i{1}; i <= s.length() / 2; ++i) {
      auto works{true};
      if (s.length() % i) {
        continue;
      }
      for (auto j{0}; j < s.length(); ++j) {
        if (s[j] != s[j % i]) {
          works = false;
          break;
        }
      }
      if (works) {
        return true;
      }
    }
    return false;
  }
};
