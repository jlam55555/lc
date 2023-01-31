class Solution {
public:
  std::string RemoveDashes(const std::string_view s) {
    std::string res{};
    for (auto c : s) {
      if (c >= 'a' && c <= 'z') {
        c ^= 0x20;
      }
      if (c != '-') {
        res.push_back(c);
      }
    }
    return res;
  }

  string licenseKeyFormatting(std::string s2, int k) {
    auto s{RemoveDashes(s2)};
    auto rem{s.length() % k};
    std::string res{s.substr(0, rem)};
    for (auto i{rem}; i < s.length(); i += k) {
      if (i) {
        res.push_back('-');
      }
      res += s.substr(i, k);
    }
    return res;
  }
};
