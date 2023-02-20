class Solution {
public:
  int countEven(int num) {
    int res{};
    for (int i{1}, sum{}; i <= num; ++i) {
      if (!(i % 10)) {
        sum -= 9;
      }
      if (!(i % 100)) {
        sum -= 9;
      }
      if (i == 1000) {
        sum -= 9;
      }
      if (++sum % 2 == 0) {
        ++res;
      }
    }
    return res;
  }
};
