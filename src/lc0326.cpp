class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n < 1) {
      return false;
    }
    auto exp{std::log(n) / std::log(3)};
    return std::pow(3, std::round(exp)) == n;
  }
};
