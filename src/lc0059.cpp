typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  void fill(vvi &m, int n, int o, int v) {
    if (n <= 0) {
      return;
    }
    if (n == 1) {
      m[o][o] = v;
      return;
    }

    for (int i = 0; i < n - 1; ++i) {
      // top, right, bottom, left
      m[o][o + i] = v + i;
      m[o + i][o + n - 1] = v + n + i - 1;
      m[o + n - 1][o + n - 1 - i] = v + 2 * n + i - 2;
      m[o + n - 1 - i][o] = v + 3 * n + i - 3;
    }

    fill(m, n - 2, o + 1, v + 4 * (n - 1));
  }

  vvi generateMatrix(int n) {
    vvi m(n, vi(n));
    fill(m, n, 0, 1);
    return m;
  }
};
