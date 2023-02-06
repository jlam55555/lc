class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    // Strings not the same length.
    if (s1.length() != s2.length()) {
      return false;
    }

    int n(s1.length()), swp1{-1};
    for (int i{}; i < n; ++i) {
      if (s1[i] != s2[i]) {
        if (swp1 == -1) {
          swp1 = i;
        } else {
          std::swap(s1[swp1], s1[i]);
          return s1 == s2;
        }
      }
    }
    // No swaps necessary.
    return swp1 == -1;
  }
};
