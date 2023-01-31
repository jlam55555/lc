class Solution {
public:
  int x1, y1, x2, y2;

  void dfs(vector<vector<int>> &mat, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] != 1) {
      return;
    }

    mat[i][j] = 2;

    x2 = max(x2, i);
    y2 = max(y2, j);

    dfs(mat, i + 1, j, m, n);
    dfs(mat, i, j + 1, m, n);
  }

  vector<vector<int>> findFarmland(vector<vector<int>> &land) {
    int m = land.size(), n = land[0].size();
    vector<vector<int>> res{};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (land[i][j] == 1) {
          x1 = i;
          y1 = j;
          x2 = INT_MIN;
          y2 = INT_MIN;
          dfs(land, i, j, m, n);
          res.push_back({x1, y1, x2, y2});
        }
      }
    }

    return res;
  }
};
