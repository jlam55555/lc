class Solution {
public:
  int maxDistance(vector<int> &colors) {
    // either the last house not the same color as the first house
    // or the first house not the same color as the last house

    int n = colors.size();
    int first = colors[0], last = colors[n - 1];

    int dist1 = INT_MIN;
    for (int i = 0; i < n; ++i) {
      if (colors[i] != first) {
        dist1 = i;
      }
    }

    int dist2 = INT_MIN;
    for (int i = n - 1; i >= 0; --i) {
      if (colors[i] != last) {
        dist2 = n - 1 - i;
      }
    }

    return max(dist2, dist1);
  }
};
