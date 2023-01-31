class Solution {
public:
  int reachNumber(int t) {
    int a = abs(t), n = ceil(-.5 + sqrt(.25 + 2 * a));
    return n + (((n + 1 >> 1) ^ a) & 1 ? (n & 1) + 1 : 0);
  }
};
