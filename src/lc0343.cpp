// This could probably be solved using DP but
// we see the following pattern empirically:
// n = 2: 1
// n = 3: 2
// n = 4: 4 = 2 * 2
// n = 5: 6 = 2 * 3
// n = 6: 9 = 3^2
// n = 7: 12 = 2^2 * 3
// n = 8: 18 = 2 * 3^2
// n = 9: 27 = 3^3
// n = 10: 36 = 3^3 * 2^2
//
// I have to imagine that the mathematical
// result of this is due to e being between
// 2 and 3 (and closer to 3).
class Solution {
public:
  int integerBreak(int n) {
    // Special case for n = 2 and n = 3.
    if (n < 4) {
      return n - 1;
    }

    // Find how many threes fit into this.
    auto threes = n / 3;
    auto remaining = n - threes * 3;
    switch (remaining) {
    case 0:
      return std::pow(3, threes);
    case 1:
      return std::pow(3, threes - 1) * 4;
    default:
      return std::pow(3, threes) * 2;
    }
  }
};
