class Solution {
public:
  bool isPerfectSquare(int num) {
    long l{1}, r{INT_MAX};
    while (l < r) {
      auto m{(l + r) / 2};
      if (m * m >= num) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l * l == num;
  }
};
