class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
      return false;
    }

    // brute force
    int n = s.length(), i, j;
    for (i = 0; i < n; ++i) {
      // try rotation i
      for (j = 0; j < n; ++j) {
        if (goal[(j + i) % n] != s[j]) {
          break;
        }
      }
      if (j == n) {
        return true;
      }
    }
    return false;
  }
};
