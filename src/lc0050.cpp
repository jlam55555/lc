class Solution {
public:
  double myPow(double x, int n) {
    return (x < 0 && n % 2 == 1 ? -1 : 1) * exp(n * log(abs(x)));
  }
};
