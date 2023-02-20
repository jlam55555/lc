class Solution {
public:
  // Feels very similar to Euclid's algorithm.
  int countOperations(int num1, int num2) {
    return num2 ? num1 / num2 + countOperations(num2, num1 % num2) : 0;
  }
};
