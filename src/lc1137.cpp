class Solution {
public:
  int tribonacci(int n) {
    int a = 0, b = 1, c = 1, c_old;

    if (!n)
      return 0;
    if (n < 3)
      return 1;

    n -= 2;
    while (n-- > 0) {
      c_old = c;
      c += a + b;
      a = b;
      b = c_old;
    }

    return c;
  }
};
