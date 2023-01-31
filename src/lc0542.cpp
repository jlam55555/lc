#define NEXTZ(i, j)                                                            \
  (VALZ(i - 1, j) || VALZ(i + 1, j) || VALZ(i, j - 1) || VALZ(i, j + 1))
#define VALZ(i, j) (VALID(i, j) && mat[i][j] == 0)
#define VALID(i, j) (i >= 0 && i < m && j >= 0 && j < n)
#define UPDATE(k, i, j)                                                        \
  if (VALID(i, j) && (mat[i][j] == 1 || mat[i][j] > k)) {                      \
    mat[i][j] = k;                                                             \
    q.push({i, j});                                                            \
  }

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q{};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] != 0) {
          if (NEXTZ(i, j)) {
            mat[i][j] = 2;
            q.push({i, j});
          }
        }
      }
    }

    while (!q.empty()) {
      pair<int, int> ij = q.front();
      q.pop();

      int i = ij.first;
      int j = ij.second;
      int k = mat[i][j] + 1;

      UPDATE(k, i - 1, j);
      UPDATE(k, i + 1, j);
      UPDATE(k, i, j - 1);
      UPDATE(k, i, j + 1);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j]) {
          --mat[i][j];
        }
      }
    }

    return mat;
  }
};
