class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    unsigned char rows[9][9] = {0}, cols[9][9] = {0}, boxes[9][9] = {0}, i, j,
                  c;
    for (i = 0; i < 9; ++i)
      for (j = 0; j < 9; ++j)
        if ((c = board[i][j] - '1') != 253 &&
            (rows[i][c]++ || cols[j][c]++ || boxes[i / 3 * 3 + j / 3][c]++))
          return false;
    return true;
  }
};
