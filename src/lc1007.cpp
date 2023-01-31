class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {

    int c1[7] = {0}, c2[7] = {0}, same[7] = {0};

    for (int i = 0; i < tops.size(); ++i) {
      ++c1[tops[i]];
      ++c2[bottoms[i]];
      if (tops[i] == bottoms[i])
        ++same[tops[i]];
    }

    for (int i = 1; i < 7; ++i) {
      if (c1[i] + c2[i] - same[i] == tops.size()) {
        return min(c1[i], c2[i]) - same[i];
      }
    }

    return -1;
  }
};
