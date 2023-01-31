class Solution {
public:
  int maxPower(string s) {
    auto res{0};
    for (auto i{0}; i < s.length(); ++i) {
      auto j{i + 1};
      while (j < s.length() && s[j] == s[i])
        ++j;
      res = std::max(res, j - i);
    }
    return res;
  }
};
