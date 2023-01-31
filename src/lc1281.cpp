class Solution {
public:
  int subtractProductAndSum(int n) {
    auto p{1}, s{0};
    while (n) {
      auto d{n % 10};
      n /= 10;
      p *= d;
      s += d;
    }
    return p - s;
  }
};
