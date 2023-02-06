class Solution {
public:
  int totalMoney(int n) {
    // I'm too lazy to do the math, so just iterate.
    int res{};
    for (int i{}, amt{6}; i < n; ++i) {
      if (i % 7 == 0) {
        amt -= 5;
      } else {
        ++amt;
      }
      res += amt;
    }
    return res;
  }
};
