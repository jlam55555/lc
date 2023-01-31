class Solution {
public:
  int countBinarySubstrings(const string s) {
    auto last_length{0};
    auto res{0};
    for (auto i{0}; i < s.length();) {
      auto j{i + 1};
      while (j < s.length() && s[j] == s[i]) {
        ++j;
      }
      auto cur_length{j - i};
      res += std::min(cur_length, last_length);
      last_length = cur_length;
      i = j;
    }
    return res;
  }
};
