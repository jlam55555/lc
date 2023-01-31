class Solution {
public:
  int trap(vector<int> &height) {

    int trapped = 0;

    // calculate cumulative maxima from left and right
    vector<int> maxLeft(height.size(), 0), maxRight(height.size(), 0);
    for (int i = 0; i < height.size(); ++i) {
      maxLeft[i] =
          !i || height[i] > maxLeft[i - 1] ? height[i] : maxLeft[i - 1];
    }
    for (int i = height.size() - 1; i >= 0; --i) {
      maxRight[i] = i == height.size() - 1 || height[i] > maxRight[i + 1]
                        ? height[i]
                        : maxRight[i + 1];
    }

    // count trapped water
    for (int i = 0; i < height.size(); ++i) {
      trapped += min(maxLeft[i], maxRight[i]) - height[i];
    }

    return trapped;
  }
};

// calculate left and right running sums; find closest running sum in
// each direction: that is the current trapped water height
//
// example: 4,2,0,3,2,5
//
//      |
// |    |
// |  | |
// || |||
// || |||
//
// 444445 maxLeft
// 555555 maxRight
