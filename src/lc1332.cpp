class Solution {
public:
  int removePalindromeSub(string s) {
    if (s.empty()) {
      return 0;
    }

    // If palindrome, then 1, else 2
    for (auto i{0}; i < (s.length() >> 1); ++i) {
      if (s[i] != s[s.length() - 1 - i]) {
        return 2;
      }
    }
    return 1;
  }
};
