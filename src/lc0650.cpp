class Solution {
public:
  int minSteps(int n) {
    int steps = 0;

    // generate prime factors
    while (n != 1) {
      for (int i = 2;; ++i) {
        if (n % i == 0) {
          steps += i;
          n /= i;
          break;
        }
      }
    }

    return steps;
  }
};
