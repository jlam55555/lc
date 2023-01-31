class Solution {
public:
  string makeFancyString(string s) {
    int i = 0, j = 0;
    for (; i < (int)s.length() - 2; ++i) {
      if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
      } else {
        s[j++] = s[i];
      }
    }
    for (; i < s.length(); ++i) {
      s[j++] = s[i];
    }

    return s.substr(0, j);
  }
};
