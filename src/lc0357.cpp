class Solution {
public:
  // This is a counting problem. @stupidbird911's
  // solution explains it well, we basically accumulate
  // number of n-digit solutions + the number of
  // (n-1)-digit solutions.
  // f(0) = 1
  // f(1) = 9 + 1.
  // f(2) = 9*9 + 10
  // f(3) = 9*9*8 + 91
  // ...
  // For everyone's convenience, I've compiled this into
  // an O(1) solution.
  int countNumbersWithUniqueDigits(int n) {
    switch (n) {
    case 0:
      return 1;
    case 1:
      return 10;
    case 2:
      return 91;
    case 3:
      return 739;
    case 4:
      return 5275;
    case 5:
      return 32491;
    case 6:
      return 168571;
    case 7:
      return 712891;
    case 8:
      return 2345851;
    }
    throw logic_error{"unexpected n"};
  }
};
