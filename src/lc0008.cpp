#include <cctype>

class Solution {
public:
  int myAtoi(string str) {
    bool positive = true;
    int i, res = 0, len = str.length(), max_div_10 = INT_MAX / 10,
           last_digit_check;
    char c;

    // scan until first digit reached
    for (i = 0; i < len; ++i) {
      c = str[i];
      if (c != ' ') {
        if (c == '-' || c == '+' || isdigit(c))
          break;

        // return 0 if first non-space character
        // encountered is not a digit
        return 0;
      }
    }

    // check for sign; last_digit_check for checking cases when res ==
    // max_div_10
    last_digit_check = 7;
    if (c == '+' || c == '-') {
      positive = c == '+';
      last_digit_check = positive ? 7 : 8;
      ++i;
    }

    for (; i < len; ++i) {
      c = str[i];

      // done processing
      if (!isdigit(c))
        break;

      if (res > max_div_10 ||
          (res == max_div_10 && ((c - '0') >= last_digit_check)))
        return positive ? INT_MAX : INT_MIN;

      res = res * 10 + (c - '0');
    }

    return (int)(positive ? res : -res);
  }
};
