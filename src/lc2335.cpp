class Solution {
public:
  // See @lee215's solution for an explanation.
  int fillCups(vector<int> &a) {
    return max({a[0], a[1], a[2], (a[0] + a[1] + a[2] + 1) / 2});
  }
};
