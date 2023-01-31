class Solution {
public:
  // See Pochmann's solution. Integer Newton's method with
  // initial guess set to `x`. This means that the result
  // monotonically decreases. The end condition (round-down)
  // works out nicely with the condition.
  int mySqrt(int x) {
    long guess{x};
    while (guess * guess > x) {
      guess = (guess + x / guess) >> 1;
    }
    return guess;
  }
};
