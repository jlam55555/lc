class Solution {
public:
  // Walk the diagonal to count how many elements mat[i][j] <= target.
  int NumElementsLe(std::vector<std::vector<int>> &mat, int n, int target) {
    int i{}, j{n - 1}, res{};
    for (; i < n; ++i) {
      for (; j >= 0 && mat[i][j] > target; --j) {
      }
      res += j + 1;
    }
    return res;
  }

  // 2-D quickselect would be difficult (need contiguous memory)
  // and would be O(n^2).
  //
  // We can try a binary search. This would be O(n*log(m))
  // where m is the range of the values. It is also more memory-
  // efficient than a quickselect would be because it doesn't do
  // any memory writes.
  //
  // I'm happy that I actually thought of this solution without
  // looking at the solutions first! It's definitely not the
  // first thing that would come to mind for me -- something like
  // a saddleback search would seem more appropriate for this
  // kind of structure. Saddleback search arises in lc0240.cpp,
  // whose problem statement includes a matrix with the same
  // structure. It also arises in the O(n) algorithm --
  // @StefanPochmann has a solution on this as expected.
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n(matrix.size()), l{matrix[0][0]}, r{matrix[n - 1][n - 1]};

    while (l < r) {
      int m((l + r) >> 1);
      if (NumElementsLe(matrix, n, m) < k) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    return l;
  }
};
