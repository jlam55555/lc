#define TON(x, y) ((x)*10000 + (y))
#define TOX(n) ((n) / 10000)
#define TOY(n) ((n) % 10000)

class Solution {
public:
  // i feel stupid and lee215 is smart
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {
    int res = 0, i = startPos[0], j = startPos[1], x = homePos[0],
        y = homePos[1];
    while (i != x) {
      i += (x - i) / abs(x - i);
      res += rowCosts[i];
    }
    while (j != y) {
      j += (y - j) / abs(y - j);
      res += colCosts[j];
    }
    return res;
  }
};
