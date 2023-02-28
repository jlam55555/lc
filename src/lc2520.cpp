class Solution {
public:
  int countDigits(int num) {
    int res{}, n{num};
    while (num) {
      res += !(n % (num % 10));
      num /= 10;
    }
    return res;
  }
};
