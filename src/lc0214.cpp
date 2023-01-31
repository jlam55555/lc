class Solution {
public:
  int shortestPalindrome(string &s, int len) {
    int l = 0, r = len - 1;

    while (r >= 0) {
      if (s[l] == s[r--]) {
        ++l;
      }
    }

    return l == len ? l : shortestPalindrome(s, l);
  }

  string shortestPalindrome(string s) {
    int i = shortestPalindrome(s, s.length());

    auto s2 = s.substr(i, s.length());
    reverse(s2.begin(), s2.end());
    return s2 + s;
  }
};
