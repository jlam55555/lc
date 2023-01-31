class Solution {
public:
  // Two pointer solution. We can greedily decrease
  // the search size by moving inwards from the left and right.
  int maxArea(vector<int> &height) {
    int l{}, r{int(height.size()) - 1}, max_water{0};
    while (l < r) {
      // Compute amount of water held by current left and right heights.
      auto cur_water = std::min(height[l], height[r]) * (r - l);
      max_water = std::max(max_water, cur_water);

      // Iterate.
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }
    return max_water;
  }
};
