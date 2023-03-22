// Really unfortunately-worded question, just like lc0521.cpp
// (Longest Uncommon Subsequence).
//
// Basically we need to look for the longest string that's not
// a subsequence of another. Given the size of the inputs, we
// can brute force this.
class Solution {
public:
  // Returns true if s1 is a subsequence of s2.
  bool IsSubsequence(std::string_view s1, std::string_view s2) {
    if (s1.length() > s2.length()) {
      return false;
    }
    for (int i{}, j{}, n1(s1.length()), n2(s2.length()); i < n1; ++i, ++j) {
      while (j < n2 && s1[i] != s2[j]) {
        ++j;
      }
      if (j == n2) {
        return false;
      }
    }
    return true;
  }

  int findLUSlength(vector<string> &strs) {
    // Sort words in order of decreasing length.
    std::sort(strs.rbegin(), strs.rend(), [](const auto &s1, const auto &s2) {
      return s1.length() < s2.length();
    });

    // Brute force: find the longest word that's not a subsequence
    // of another word.
    int n(strs.size()), res{-1};
    for (int i{}; i < n; ++i) {
      for (int j{}; j < n; ++j) {
        if (i != j && IsSubsequence(strs[i], strs[j])) {
          goto continue_;
        }
      }
      return strs[i].length();
    continue_:;
    }

    return -1;
  }
};
