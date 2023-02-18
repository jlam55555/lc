class Solution {
public:
  // General idea:
  // If n is odd, we want (n+1)/2 or (n-1)/2 to be closer to a power of 2.
  // I just tried the following based on this intution, and it seems
  // to have worked.
  //
  // This is O(log(n)) time, O(1) space.
  int integerReplacement(long n) {
    // Base case. This holds true for n=1, 2, 3.
    // Note that 3 is an exception to the rule for
    // odd numbers below, so we need this special handling for it.
    if (n < 4) {
      return n - 1;
    }

    // Even number.
    if (!(n & 1)) {
      return 1 + integerReplacement(n >> 1);
    }

    // Odd number.
    // n-1 only flips one bit, but makes the number
    // smaller. n+1 will make the number larger, but can
    // flip more than one bit if the second-lowest-order bit
    // is set.
    return 1 + integerReplacement(n & 2 ? n + 1 : n - 1);
  }
};
