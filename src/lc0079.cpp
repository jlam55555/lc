class Solution {
public:
  bool dfs(vector<vector<char>> &b, int i, int j, string &w, int p) {
    if (p == w.length()) {
      return true;
    }

    if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() ||
        b[i][j] != w[p]) {
      return false;
    }

    // make letter lowercase
    b[i][j] ^= 0x20;

    bool res = dfs(b, i - 1, j, w, p + 1) || dfs(b, i + 1, j, w, p + 1) ||
               dfs(b, i, j - 1, w, p + 1) || dfs(b, i, j + 1, w, p + 1);

    // revert letter
    b[i][j] ^= 0x20;

    return res;
  }

  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (dfs(board, i, j, word, 0)) {
          return true;
        }
      }
    }

    return false;
  }
};
