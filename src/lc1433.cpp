class Solution {
public:
  bool helper(string &s1, string &s2) {
    int hist1[26] = {0}, hist2[26] = {0};
    int n = s1.length();
    for (int i = 0; i < n; ++i) {
      ++hist1[s1[i] - 'a'];
      ++hist2[s2[i] - 'a'];
    }

    int i = 0, j = 0;
    while (n-- > 0) {
      // find next instance of i, j
      while (!hist1[i])
        ++i;
      while (!hist2[j])
        ++j;

      // check if invalid
      if (j > i) {
        return false;
      }

      // go to next char
      --hist1[i];
      --hist2[j];
    }

    return true;
  }

  bool checkIfCanBreak(string s1, string s2) {
    return helper(s1, s2) || helper(s2, s1);
  }
};
