class Solution {
public:
  // Intuition:
  // - For each (nums[i], nums[j]) pair, find the range of side
  //   lengths nums[k] for the longest side.
  // - We maintain that nums[i] <= nums[j] <= nums[k] by first
  //   sorting the array.
  // - In order for the triangle to be valid, nums[i] + nums[j] >
  //   nums[k]. (Shorter sides must sum to longer than the longest
  //   side.)
  //
  // Algorithm:
  // - Traverse through (i, j) pairs after sorting the array nums.
  //   For each pair, find the range of values k such that (i, j, k)
  //   is a valid triangular triplet. Any value of `k` such
  //   that `nums[k] >= nums[i] && nums[k] >= nums[j]` and
  //   `nums[i] + nums[j] > nums[k]` forms a valid triplet, so
  //   we simply iterate `k` until this condition is false.
  // - An optimization upon the naive O(N^3) algorithm is that for
  //   every value of `i`, _both_ `j` and `k` increase monotonically.
  //   We can rephrase the above algorithm as saying: for each value
  //   of `i`, find (j, k) pairs that form valid triangles. Since
  //   `j` and `k` both increase monotonically for each `i`, the inner
  //   `j` loop is O(N) rather than O(N^2), and the overall algorithm
  //   is O(N^2).
  // - Note that this algorithm breaks down if zeroes are involved,
  //   hence the special handling.
  int triangleNumber(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int N(nums.size());

    // Go past all the zeroes; they can't form valid triangles.
    int i{};
    while (i < N && !nums[i]) {
      ++i;
    }

    // O(N^2) loop.
    int res{};
    for (; i < N; ++i) {
      // Find all (j, k) pairs that form a valid triangle with `i`.
      // This loop is O(N).
      int j{i + 1}, k{i + 2};
      for (; j < N; ++j) {
        while (k < N && nums[i] + nums[j] > nums[k]) {
          ++k;
        }
        // Found valid triangles: (i, j, j+1) through (i, j, k-1).
        // There are (k-1)-(j+1)+1 = k-j-1 triangles here.
        res += k - j - 1;
      }
    }
    return res;
  }
};
