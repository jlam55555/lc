class Solution {
public:
  int numberOfCuts(int n) { return n == 1 ? 0 : n & 1 ? n : n / 2; }
};
