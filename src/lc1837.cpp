class Solution {
public:
  int sumBase(int n, int k) {
    int res{};
    while (n) {
      auto digit = n % k;
      res += digit;
      n /= k;
    }
    return res;
  }
};
