class Solution {
public:
  // We can do a bin sort. This is O(n) time and O(1) space.
  vector<int> sortEvenOdd(vector<int> &nums) {
    int freqs[2][100]{}, n(nums.size());
    for (int i{}; i < n; ++i) {
      ++freqs[i % 2][nums[i] - 1];
    }
    for (int i{}, j{}, k{99}; i < n; i += 2) {
      while (!freqs[0][j]--) {
        ++j;
      }
      nums[i] = j + 1;

      if (i < n - 1) {
        while (!freqs[1][k]--) {
          --k;
        }
        nums[i + 1] = k + 1;
      }
    }
    return nums;
  }
};
