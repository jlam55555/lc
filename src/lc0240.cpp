typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  bool search(vvi &matrix, int t, int b, int l, int r, int n) {
    if (l == r || t == b) {
      return false;
    }

    int my = (t + b) / 2, mx = (l + r) / 2;
    if (n == matrix[my][mx]) {
      return true;
    }
    // smaller, search left and up
    if (n < matrix[my][mx]) {
      return search(matrix, t, b, l, mx, n) || search(matrix, t, my, mx, r, n);
    }
    // larger, search right and down
    else {
      return search(matrix, t, b, mx + 1, r, n) ||
             search(matrix, my + 1, b, l, mx + 1, n);
    }
  }

  bool searchMatrix(vvi &matrix, int target) {
    return search(matrix, 0, matrix.size(), 0, matrix[0].size(), target);
  }
};
