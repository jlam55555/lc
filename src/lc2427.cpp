class Solution {
public:
  int commonFactors(int a, int b) {
    int res{};
    for (int i{1}, max{std::max(a, b) / 2}; i <= max; ++i) {
      res += !(a % i) && !(b % i);
    }
    return res + (a == b);
  }
};
