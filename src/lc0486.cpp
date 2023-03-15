// Almost exactly the same problem as lc0464.cpp.
// This problem is slightly different however:
// - We run pretty fast without memoization, since there are
//   only two options we can choose each time (thus having a
//   exponential tree of size 2^N rather than K^N, which isn't
//   terrible since N<=20).
// - There is an asymmetric end condition, which requires some
//   messier endgame logic.
//
// I was able to figure out a solution without memoization
// that was very similar to that of lc0464.cpp. The memoization
// logic is inspired by @chidong's answer: we store the best
// score for each subarray. (I was previously trying to store
// who would win for each subarray, which isn't enough
// information to determine a winner.)
//
// The bottom-up DP solutions given by the editorial (both 2-D
// and 1-D DP) are pretty cool. I only use the simple memoized
// recursive solution from the second solution in the editorial.

#define CAN_FORCE_WIN 1
#define CANNOT_FORCE_WIN 2

// Brute force with memoization.
class Solution {
  // This memoized array stores the best score for each
  // subarray [l, r].
  std::optional<int> dp_[20][20]{};

public:
  int PredictTheWinner(const std::vector<int> &nums, int l, int r) {
    auto &memo{dp_[l][r]};
    return memo ? *memo
                : *(memo =
                        l == r
                            ? nums[l]
                            : std::max(
                                  nums[l] - PredictTheWinner(nums, l + 1, r),
                                  nums[r] - PredictTheWinner(nums, l, r - 1)));
  }

  bool PredictTheWinner(vector<int> &nums) {
    return PredictTheWinner(nums, 0, nums.size() - 1) >= 0;
  }
};
