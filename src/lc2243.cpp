class Solution {
public:
  int SumOfGroup(const std::string_view s) {
    int sum{0};
    for (auto c : s) {
      sum += c - '0';
    }
    return sum;
  }

  std::string DigitSumHelper(const std::string_view s, int k) {
    std::string res{};

    for (auto i{0}; i < s.length(); i += k) {
      res += std::to_string(SumOfGroup(s.substr(i, k)));
    }

    return res;
  }

  string digitSum(string s, int k) {
    while (s.length() > k) {
      s = DigitSumHelper(s, k);
    }
    return s;
  }
};
