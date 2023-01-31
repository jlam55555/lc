class Solution {
public:
  void rotate(vector<vector<int>> &m) {
    for (int d = m.size(), i = 0, j, k, ii, jj, tmp, first; i < (d + 1) / 2;
         ++i)
      for (j = 0; j < d / 2; m[ii][jj] = first, ++j)
        for (first = m[ii = i][jj = j], k = 4; --k;
             m[ii][jj] = m[d - jj - 1][tmp = ii], ii = d - jj - 1, jj = tmp)
          ;
  }
};
