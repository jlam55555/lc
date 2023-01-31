class Solution {
public:
  bool isThree(int n) {
    if (n < 4)
      return false;

    if ((int)sqrt(n) * sqrt(n) != n)
      return false;

    // if square and no other divisors
    for (int i = 2; i < sqrt(n); ++i) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }
};
