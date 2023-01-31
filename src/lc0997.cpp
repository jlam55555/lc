class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    // look for someone everyone trusts
    // that person should not trust anyone
    int tc[1001] = {0}, tc2[1001] = {0};
    for (auto e : trust) {
      ++tc[e[1]];
      ++tc2[e[0]];
    }

    int cand = 0, candi = -1;
    for (int i = 1; i <= n; ++i) {
      if (tc[i] == n - 1 && tc2[i] == 0) {
        candi = i;
        if (++cand == 2) {
          return -1;
        }
      }
    }

    return candi;
  }
};
