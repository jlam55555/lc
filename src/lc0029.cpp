class Solution {
public:
  int divide(int dividend, int divisor) {
    unsigned int positive = 1, res, currShift;

    if (dividend > 0) {
      dividend = -dividend;
      positive ^= 1;
    }
    if (divisor > 0) {
      divisor = -divisor;
      positive ^= 1;
    }

    // now we have to divide two negative numbers
    for (res = 0, currShift = -1; dividend <= divisor; res |= 1 << currShift,
        dividend -= (unsigned int)divisor << currShift, currShift = -1)
      while (++currShift < 31 &&
             (unsigned int)divisor << currShift + 1 >= dividend)
        ;

    return res == INT_MIN ? positive ? INT_MAX : INT_MIN
           : positive     ? res
                          : -res;
  }
};
