class Solution {
public:
  std::string convertToBase7(int num) noexcept {
    // Edge case
    if (!num) {
      return "0";
    }

    auto neg{num < 0};
    std::string res{neg ? "-" : ""};
    num = std::abs(num);

    while (num) {
      res.push_back((num % 7) + '0');
      num /= 7;
    }
    std::reverse(res.begin() + neg, res.end());
    return res;
  }
};
