/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {

    long l{1}, r{INT_MAX};
    while (l < r) {
      auto m{(l + r) / 2};
      // m >= target
      if (guess(m) <= 0) {
        r = m;
      }
      // m < target
      else {
        l = m + 1;
      }
    }

    return l;
  }
};
