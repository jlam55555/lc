class Solution {
public:
  std::string removeOuterParentheses(const std::string_view s) {
    std::string res;
    for (auto i{0}; i < s.length();) {
      auto depth{0};
      auto j{i};
      do {
        depth += s[j++] == '(' ? 1 : -1;
      } while (depth);
      // Current valid substring from [i,j)
      res += s.substr(i + 1, j - i - 2);
      i = j;
    }
    return res;
  }
};
