class Solution {
public:
  int getMaximumGenerated(int n) {
    vector<int> res(n / 2 + 3);
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;
    if (n == 4)
      return 2;
    res[0] = 0;
    res[1] = 1;
    int max = 0;
    for (int i = 2; i <= n / 2 + 1; ++i) {
      if (i % 2 == 0)
        res[i] = res[i / 2];
      else
        res[i] = res[i / 2] + res[i / 2 + 1];

      if (res[i] + res[i - 1] > max && 2 * (i - 1) + 1 <= n) {
        max = res[i] + res[i - 1];
      }
      // cout << i << " " << res[i] << endl;
    }
    return max;
  }
};
