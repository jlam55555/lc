#define ins(x, y)                                                              \
  if (x < R && x >= 0 && y < C && y >= 0) {                                    \
    res[pos][0] = x;                                                           \
    res[pos++][1] = y;                                                         \
    cout << x << " " << y;                                                     \
  }

class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {

    int pos = 0;
    int level = 0;

    vector<vector<int>> res(R * C, vector<int>(2));

    if (R * C == 0)
      return res;

    res[0][0] = r0;
    res[0][1] = c0;
    ++pos;

    while (pos < R * C) {
      ++level;
      for (int i = 0; i < level; ++i) {
        ins(r0 - level + i, c0 - i);
        ins(r0 + level - i, c0 + i);
        ins(r0 - i, c0 + level - i);
        ins(r0 + i, c0 - level + i);
      }
    }

    return res;
  }
};
