typedef bitset<400> bd;

class Solution {
public:
  int dfs(vector<vector<int>> &g, vector<int> &stk, int i, int j, int di,
          int dj, bd &b, int t) {

    int pos = i * dj + j, res = 0;

    // out of bounds, already covered this square, or square is blocked
    if (i < 0 || i >= di || j < 0 || j >= dj || g[i][j] == -1 || b.test(pos)) {
      return 0;
    }

    // reached end point, check if all squares are covered
    if (g[i][j] == 2) {
      return b.count() == t;
    }

    // ordinary dfs
    b.set(pos);
    stk.push_back(pos);

    res += dfs(g, stk, i + 1, j, di, dj, b, t);
    res += dfs(g, stk, i - 1, j, di, dj, b, t);
    res += dfs(g, stk, i, j + 1, di, dj, b, t);
    res += dfs(g, stk, i, j - 1, di, dj, b, t);

    stk.pop_back();
    b.reset(pos);

    return res;
  }

  int uniquePathsIII(vector<vector<int>> &grid) {
    int d1 = grid.size(), d2 = grid[0].size();

    // find starting square, count how many squares
    // need to be found (total - blocked - 1)
    int si, sj, blockedCount = 0;
    for (int i = 0; i < d1; ++i) {
      for (int j = 0; j < d2; ++j) {
        if (grid[i][j] == 1) {
          si = i;
          sj = j;
        } else if (grid[i][j] == -1) {
          ++blockedCount;
        }
      }
    }

    int desiredCount = d1 * d2 - blockedCount - 1;
    bd bd{};
    vector<int> stk{};
    return dfs(grid, stk, si, sj, d1, d2, bd, desiredCount);
  }
};
