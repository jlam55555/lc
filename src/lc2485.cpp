class Solution {
public:
  // A little bit of math.
  // Sum of numbers in [1,x] = x(x+1)/2 = a
  // Sum of numbers in [x,n] = n(n+1)/2 - a + x = a
  //
  // Given n, we want to find an integer x such
  // that the above relation holds true.
  //
  // Solving:
  // n(n+1)/2 - x(x+1)/2 + x = x(x+1)/2
  // n(n+1)/2 = x^2
  int pivotInteger(int n) {
    auto x{std::sqrt(n * (n + 1) / 2.)};
    return x == (int)x ? x : -1;
  }
};
