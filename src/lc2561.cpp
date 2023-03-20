// The check if it's impossible is easy: we simply need to see if
// there are an even number of each element.
//
// Optimal strategy for swapping:
// - Choose the smallest element from either side and use it to
//   swap the two largest elements from both sides.
// - Choose the smallest swappable element from either side and
//   swap it with the largest swappable element from the other side.
//
// I came up with a solution that is essentially a less-optimized
// version of @RealFan's solution. This solution takes some hints from
// that to achieve a similar O(n) space and time solution.
class Solution {
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2) {
    std::unordered_map<int, int> freqs;
    int n(basket1.size()), smallest{INT_MAX};
    for (int i{}; i < n; ++i) {
      ++freqs[basket1[i]];
      --freqs[basket2[i]];
      smallest = std::min({smallest, basket1[i], basket2[i]});
    }

    std::vector<int> diffs;
    for (auto [val, freq] : freqs) {
      // Impossible.
      if (freq & 1) {
        return -1;
      }

      // If zero, already balanced, otherwise keep track
      // of how unbalanced they are.
      for (int i{}; i < std::abs(freq) / 2; ++i) {
        diffs.push_back(val);
      }
    }

    // This is based on a modified version of @RealFan's solution.
    // My original solution involved having two `diffs` arrays,
    // one for `basket1` and one for `basket2`, and I sorted the
    // `diffs` array. @RealFan's solution made me realize that we
    // only need one array (to store all numbers that need to be
    // transferred) and that we don't need to sort at all; we just
    // need to quickselect up to m/2 numbers.
    auto median{diffs.begin() + diffs.size() / 2};
    std::nth_element(diffs.begin(), median, diffs.end());
    return std::accumulate(diffs.begin(), median, 0ll,
                           [smallest](long long acc, int val) {
                             return acc + std::min(val, 2 * smallest);
                           });
  }
};
