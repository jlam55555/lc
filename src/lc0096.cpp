class Solution {
public:
  int dfs(int *mm, int n) {
    int res = 0;
    for (int m = 0; m < n; ++m) {
      int left = m, right = n - m - 1;
      res += mm[left] * mm[right];
    }
    return res;
  }

  int numTrees(int n) {
    int mm[n + 1];
    mm[0] = 1;

    for (int i = 1; i <= n; ++i) {
      mm[i] = dfs(mm, i);
    }

    return mm[n];
  }
};
