#define N 9
#define ROW(n) (n / N)
#define COL(n) (n % N)
#define BLK(n) (ROW(n) / 3 * 3 + COL(n) / 3)

#define NIJ(i, j) (N * i + j)
#define BLKIJ(i, j) (i / 3 * 3 + j / 3)

#define RS 45

int bls[N][N] = {
    {0, 1, 2, 9, 10, 11, 18, 19, 20},     {3, 4, 5, 12, 13, 14, 21, 22, 23},
    {6, 7, 8, 15, 16, 17, 24, 25, 26},    {27, 28, 29, 36, 37, 38, 45, 46, 47},
    {30, 31, 32, 39, 40, 41, 48, 49, 50}, {33, 34, 35, 42, 43, 44, 51, 52, 53},
    {54, 55, 56, 63, 64, 65, 72, 73, 74}, {57, 58, 59, 66, 67, 68, 75, 76, 77},
    {60, 61, 62, 69, 70, 71, 78, 79, 80}};

class Solution {
public:
  bool consistent(int b[N][N], int n, int v) {
    // attempt to place i at position n
    // returns true if this doesn't break any constraints
    int i = ROW(n);
    int j = COL(n);
    int bl = BLK(n);

    for (int k = 0; k < N; ++k) {
      int blk = bls[bl][k];
      if (b[i][k] == v || b[k][j] == v || b[ROW(blk)][COL(blk)] == v) {
        return false;
      }
    }

    b[i][j] = v;
    return true;
  }

  bool dfs(int b[N][N], vector<int> us, int usi) {
    // done
    if (usi == us.size()) {
      return true;
    }

    // attempt to place all nine numbers at position us[usi]
    for (int i = 1; i <= 9; ++i) {
      int n = us[usi];
      if (consistent(b, n, i) && dfs(b, us, usi + 1)) {
        return true;
      }

      b[ROW(n)][COL(n)] = 0;
    }

    return false;
  }

  void solveSudoku(vector<vector<char>> &board) {
    int b[N][N] = {0};
    vector<int> unseen{};

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        char v = board[i][j] == '.' ? 0 : (board[i][j] - '0');

        b[i][j] = v;
        if (!v) {
          unseen.push_back(NIJ(i, j));
        }
      }
    }

    dfs(b, unseen, 0);

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        board[i][j] = b[i][j] + '0';
      }
    }
  }
};
