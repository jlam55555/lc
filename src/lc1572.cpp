class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int len = mat.size(), sum = 0;
    for (int i = 0; i < len; ++i)
      sum += mat[i][i] + mat[i][len - 1 - i];
    if (len % 2)
      sum -= mat[len / 2][len / 2];

    return sum;
  }
};
