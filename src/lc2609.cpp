// Very common Leetcode easy question.
class Solution {
public:
  int findTheLongestBalancedSubstring(string s) {
    int res{};
    for (int i{}, n(s.length()); i < n;) {
      int j{i};
      while (j < n && s[j] == '0') {
        ++j;
      }
      int k{j};
      while (k < n && s[k] == '1') {
        ++k;
      }
      res = std::max(res, std::min(j - i, k - j) * 2);
      i = k;
    }
    return res;
  }
};
