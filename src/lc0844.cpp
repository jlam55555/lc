class Solution {
public:
  string trace(string &s) {
    int i, j;
    for (i = 0, j = 0; i < s.length();) {
      if (s[i] == '#') {
        ++i;
        j = max(j - 1, 0);
      } else {
        s[j++] = s[i++];
      }
    }

    return s.substr(0, j);
  }

  bool backspaceCompare(string s, string t) { return trace(s) == trace(t); }
};
