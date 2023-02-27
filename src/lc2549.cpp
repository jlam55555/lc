class Solution {
public:
  // Return all the integers in the interval
  // [2, n]. This is because we add the number
  // x-1 for each integer x on each day (except
  // for x=2).
  int distinctIntegers(int n) { return std::max(n - 1, 1); }
};
