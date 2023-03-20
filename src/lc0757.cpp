// This sounds almost exactly like lc0452.cpp, except that now
// we have to have two "darts" for each "balloon" (interval).
//
// Most of this solution is copied from lc0452.cpp.
//
// Continuing the balloon analogy, the optimal strategy looks
// like so:
// 0. Sort the balloons by the end of their interval.
// 1. Take the first balloon. Put two darts at the end
//    of the balloon interval.
// 2. Scan through next balloons until we find one that
//    cannot be popped using the two darts. Put a dart
//    through the end of this.
// 3. Repeat step 2 using the latest two darts.
// 4. At some point we may reach a point where a new
//    balloon cannot be popped by either of the last
//    two darts. That means we have reached a new non-
//    overlapping set, and we start back from step 1
//    (place two darts rather than one).

class Solution {
public:
  bool PoppedBy(std::vector<int> &balloon, int dart) {
    return balloon[0] <= dart && dart <= balloon[1];
  }

  int intersectionSizeTwo(vector<vector<int>> &balloons) {
    std::sort(balloons.begin(), balloons.end(),
              [](const auto &b1, const auto &b2) { return b1[1] < b2[1]; });

    int res{};

    // Outer loop iterates over non-overlapping sets of balloons.
    for (int i{}, n(balloons.size()); i < n; res += 2) {
      int j{i + 1}, prev1{balloons[i][1]}, prev2{prev1 - 1};

      // Find next balloon that cannot be popped by prev2.
      while (j < n && PoppedBy(balloons[j], prev2)) {
        ++j;
      }

      // Keep looping until we find next balloon that cannot be
      // popped by prev1 (iterate over one overlapping set of
      // balloons).
      while (j < n && PoppedBy(balloons[j], prev1)) {
        ++res;
        prev2 = prev1;
        prev1 = balloons[j][1];
        // Small edge case: take for example the input:
        // [[1,3],[3,7],[5,7],[7,8]]
        if (prev1 == prev2) {
          --prev2;
        }

        // Find next balloon that cannot be popped by prev2.
        while (j < n && PoppedBy(balloons[j], prev2)) {
          ++j;
        }
      }

      // By this point balloons[j] cannot be popped by either prev1
      // or prev2.
      i = j;
    }
    return res;
  }
};
