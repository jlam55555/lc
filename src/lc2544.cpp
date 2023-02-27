class Solution {
public:
  int alternateDigitSum(int n) {
    int i{}, res{};
    while (n) {
      res += (n % 10) * ((i & 1) ? 1 : -1);
      n /= 10;
      ++i;
    }
    return res * ((i & 1) ? -1 : 1);
  }
};
