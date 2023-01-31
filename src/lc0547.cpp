class UF {
public:
  vector<int> data, groupSizes;
  int groupsCount;

  UF(int size) : data(size), groupSizes(size, 1), groupsCount{size} {
    for (int i = 0; i < size; ++i) {
      data[i] = i;
    }
  }

  int find(int n) {
    if (data[n] == n) {
      return n;
    }
    return data[n] = find(data[n]);
  }

  bool join(int m, int n) {
    int rm, rn;
    if ((rm = find(m)) == (rn = find(n))) {
      return false;
    }

    int gsm = groupSizes[rm], gsn = groupSizes[rn], gs = gsm + gsn;
    if (gsm < gsn) {
      groupSizes[rn] = gs;
      data[rm] = rn;
    } else {
      groupSizes[rm] = gs;
      data[rn] = rm;
    }

    --groupsCount;
    return true;
  }
};

class Solution {
public:
  // the UF solution is nice, but the DFS solution is also crazy elegant:
  // go down rows on one, columns on the other

  int findCircleNum(vector<vector<int>> &isConnected) {
    UF uf{(int)isConnected.size()};
    for (int i = 0; i < isConnected.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (isConnected[i][j]) {
          uf.join(i, j);
        }
      }
    }

    return uf.groupsCount;
  }
};
