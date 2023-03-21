// Optimal strategy is to try not to have one pile
// with all the stones in it at the end. Of course,
// we can't always avoid this. Thus, we greedily
// always choose a stone from the largest pile.
//
// This feels very similar to lc2335.cpp.
class Solution {
public:
  int maximumScore(int a, int b, int c) {
    // Cannot have optimal solution.
    if (a > b + c) {
      return b + c;
    }
    if (b > a + c) {
      return a + c;
    }
    if (c > a + b) {
      return a + b;
    }

    // Can have optimal solution.
    return (a + b + c) / 2;
  }
};
