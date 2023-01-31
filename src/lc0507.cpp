class Solution {
public:
  // Returns divisors of a number.
  // Includes 1, excludes n.
  // Doesn't duplicate sqrt for perfect squares.
  std::vector<int> Divisors(int n) {
    auto sn{sqrt(n)};
    std::vector<int> res{1};
    for (auto i{2}; i < sn; ++i) {
      if (!(n % i)) {
        res.push_back(i);
        res.push_back(n / i);
      }
    }
    if (sn == int(sn)) {
      res.push_back(sn);
    }
    return res;
  }

  bool checkPerfectNumber(int num) {
    // Edge case.
    if (num == 1) {
      return false;
    }

    auto sum{0};
    for (const auto i : Divisors(num)) {
      sum += i;
    }
    return sum == num;
  }
};
