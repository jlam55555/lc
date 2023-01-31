class Solution {
public:
  bool isSubsequence(string s, string t) {
    auto i{0}, j{0};
    if (s.empty()) {
      return true;
    }
    for (; j < t.length(); ++j) {
      if (s[i] == t[j]) {
        ++i;
        if (i == s.length()) {
          return true;
        }
      }
    }
    return false;
  }

  bool isSubsequenceOld(string s, string t) {
    if (s.length() > t.length()) {
      return false;
    }

    // i points to position in s,
    // j points to position in t
    for (auto i{0}, j{0}; i < s.length(); ++i, ++j) {
      while (j < t.length() && t[j] != s[i]) {
        ++j;
      }
      if (j == t.length()) {
        return false;
      }
    }
    return true;
  }
};
