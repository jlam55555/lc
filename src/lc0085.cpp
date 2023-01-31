class Solution {
public:
  int largestRectangleArea(vector<char> &heights) {

    // find the first on the left and right shorter than the current
    int l = heights.size();
    vector<int> left(l), right(l);
    left[0] = -1;
    right[l - 1] = l;
    for (int i = 1; i < l; ++i) {
      int p = i - 1;
      while (p >= 0 && heights[p] >= heights[i]) {
        p = left[p];
      }
      left[i] = p;

      p = (l - 1 - i) + 1;
      while (p < l && heights[p] >= heights[l - 1 - i]) {
        p = right[p];
      }
      right[l - 1 - i] = p;
    }

    // get the maximum size
    int res = INT_MIN;
    for (int i = 0; i < l; ++i) {
      res = max(res, heights[i] * (right[i] - left[i] - 1));
    }

    return res;
  }

  int maximalRectangle(vector<vector<char>> &matrix) {

    // 2-D version of lc_0084
    int maxRect = INT_MIN, m = matrix.size(), n = m ? matrix[0].size() : 0;

    if (!m || !n) {
      return 0;
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[i][j] -= '0';
        if (i && matrix[i][j]) {
          matrix[i][j] += matrix[i - 1][j];
        }
      }

      // perform lc_0084
      maxRect = max(maxRect, largestRectangleArea(matrix[i]));
    }

    return maxRect;
  }
};
