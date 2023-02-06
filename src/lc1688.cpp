class Solution {
public:
  int numberOfMatches(int n) {
    int res{};
    while (n > 1) {
      res += n >> 1;
      n = (n + 1) >> 1;
    }
    return res;
  }
};
