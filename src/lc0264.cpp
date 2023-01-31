class Solution {
public:
  // coin change problem
  int nthUglyNumber(int n) {
    int k[n], dp2, dp3, dp5, i;

    for (dp2 = dp3 = dp5 = 0, k[0] = i = 1; i < n; ++i) {
      k[i] = min(k[dp2] * 2, min(k[dp3] * 3, k[dp5] * 5));
      if (k[i] == k[dp2] * 2)
        ++dp2;
      if (k[i] == k[dp3] * 3)
        ++dp3;
      if (k[i] == k[dp5] * 5)
        ++dp5;
    }

    return k[n - 1];
  }
};
