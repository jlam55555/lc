#define MOD 1000000007

class Solution {
public:
  // This is very similar to lc0046.cpp (Jump Game II),
  // with the addition of wildcards. We only need to store
  // the number of ways to decode the message up to the last
  // two characters to determine the number of ways to
  // decode the next character.
  int numDecodings(string s) {
    // `prev1` is the number of ways to decode up to the
    // previous character, `prev2` is the same for the
    // second most recent character. Similarly, `c0` represents
    // the current character and `c1` is the previous character.
    long prev1{1}, prev2{1};
    char c0, c1;

    for (int i{}, n(s.length()); i < n; ++i) {
      // Count the number of ways this can form a one-digit number.
      c0 = s[i];
      auto one_digit_options{c0 == '0' ? 0 : (c0 == '*' ? 9 : 1)};

      // Count the number of ways this can form a two-digit number.
      int two_digit_options{};
      if (i) {
        if (c0 == '*' && c1 == '*') {
          two_digit_options = 15;
        } else if (c0 == '*') {
          two_digit_options = c1 == '2' ? 6 : (c1 == '1' ? 9 : 0);
        } else if (c1 == '*') {
          two_digit_options = c0 <= '6' ? 2 : 1;
        } else {
          two_digit_options = (c1 == '1') || (c1 == '2' && c0 <= '6');
        }
      }

      // Iterate.
      std::tie(prev1, prev2) = std::tuple(
          (one_digit_options * prev1 + two_digit_options * prev2) % MOD, prev1);
      c1 = c0;
    }

    return prev1 % MOD;
  }
};
