class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    // just look at first two edges
    int v11 = edges[0][0], v12 = edges[0][1], v21 = edges[1][0],
        v22 = edges[1][1];

    return v11 == v21 || v11 == v22 ? v11 : v12;
  }
};
