class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int l, r, m, dim1 = matrix.size(), dim2 = matrix[0].size(),
                 len = dim1 * dim2, cell;

    for (l = 0, r = len; l < r;) {
      m = (l + r) >> 1;

      cell = matrix[m / dim2][m % dim2];

      if (cell == target) {
        return true;
      } else if (cell < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    return false;
  }
};
