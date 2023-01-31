class Solution {
public:
  int balancedStringSplit(string s) {
    int depth{0}, res{0};
    for (auto c : s) {
      depth += c == 'R' ? 1 : -1;
      res += !depth;
    }
    return res;
  }
};
