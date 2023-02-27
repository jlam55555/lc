class Solution {
public:
  int Remap(int num, int from, int to) {
    int res{}, multiplier{1};
    while (num) {
      if (num % 10 == from) {
        res += multiplier * to;
      } else {
        res += multiplier * (num % 10);
      }
      multiplier *= 10;
      num /= 10;
    }
    return res;
  }

  // Remap the largest non-9 digit to 9,
  // and the largest non-0 digit to 0.
  int minMaxDifference(int num) {
    int min_digit{9}, max_digit{0}, copy{num};
    while (num) {
      min_digit = num % 10 == 9 ? min_digit : num % 10;
      max_digit = num % 10 == 0 ? max_digit : num % 10;
      num /= 10;
    }
    return Remap(copy, min_digit, 9) - Remap(copy, max_digit, 0);
  }
};
