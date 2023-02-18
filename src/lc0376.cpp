class Solution {
public:
  // Algorithm: basically need to count the number of local
  // minima and maxima.
  //
  // Slope-counting inspired by lc0135.cpp.
  int wiggleMaxLength(vector<int> &nums) {
    int slope{}, extrema{1};

    for (int i{1}; i < nums.size(); ++i) {
      auto new_slope{nums[i] < nums[i - 1] ? -1 : (nums[i] > nums[i - 1])};
      if (new_slope) {
        if (new_slope != slope) {
          ++extrema;
        }
        slope = new_slope;
      }
    }

    return extrema;
  }
};
