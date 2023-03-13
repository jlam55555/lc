// See also lc0473.cpp and lc1655.cpp, which are also variants
// of the bin-packing problem and use some of the optimizations
// used here.
class Solution {
public:
  // This kind of feels like the coin change algorithm, with a few
  // "rounds." This is inspired by @GraceMeng's and @lee215's solutions.
  // My original solution was incredibly close to GraceMeng's solution,
  // but both my solution and GraceMeng's led to TLE on Leetcode.
  //
  // Note: this is a variant of the bin-packing problem. Hence there is
  // no solution asymptotically better than an O(2^n) (exponential) search.
  //
  // This uses some optimizations to improve the performance, such as:
  // - Quitting once we've found the second-to-last bucket. (Inspired by
  //   @GraceMeng's solution.)
  // - Exiting early if the largest element is greater than the bucket
  //   size (inspired by a comment on @GraceMeng's solution).
  // - Exiting early if the sum is not evenly divisible by k.
  // - Sorting the coins array in reverse order. This is due to the
  //   observation that the a solution to fill the buckets (if it exists)
  //   is usually close to a greedy result of choosing the largest coin
  //   that will fit in the bucket first.
  // - Reducing the search space by one element. We do this by putting
  //   the first element into the first bucket, and thus we never have
  //   to check for this element again in later searches. (This was
  //   inspired by @lee215's solution.)
  //
  // In the worst case, this is O(k*2^(n-1)) time. It is O(log(n)) space.
  // Notes on time/space complexity:
  // - The 2^(n-1) rather than 2^n time complexity is due to reducing the
  //   search space by one element.
  // - The factor of k is due to repeating a search for each of the k
  //   buckets.
  // - This is an exponential search/backtracking algorithm, and is
  //   basically the worst-case. But I don't think we can do any better
  //   (i.e., a greedy algorithm will fail some cases, but we use sorting
  //   to try to be greedy when possible).
  // - Many of the posted solutions use a second array to mark which coins
  //   have been used, thus leading to O(n) space. I simply mark used
  //   elements in the original array by setting coins to 0, thus leading
  //   to no extra space. However, there is still a recursive stack with
  //   maximum depth=n-1, so the space complexity is O(log(n-1)).
  // - 1 <= n <= 16 by the problem statement.
  bool CoinChange(std::vector<int> &coins, int per_bucket, int k, int n,
                  int sum = 0, int i = 1) {

    // Found a valid bucket, move on.
    if (sum == per_bucket) {
      return CoinChange(coins, per_bucket, k - 1, n);
    }

    // Found a valid solution.
    if (k == 1) {
      return true;
    }

    // Recurse. Mark a coin as visited by setting it to zero.
    // Note that we start at the position we left off in the bucket.
    for (; i < n; ++i) {
      if (coins[i] && sum + coins[i] <= per_bucket) {
        auto tmp{coins[i]};
        coins[i] = 0;
        if (CoinChange(coins, per_bucket, k, n, sum + tmp, i + 1)) {
          return true;
        }
        coins[i] = tmp;
      }
    }

    // No solutions found.
    return false;
  }

  bool canPartitionKSubsets(std::vector<int> &nums, int k) {
    // Get total sum.
    int n(nums.size());
    auto sum{std::accumulate(nums.begin(), nums.end(), 0)};
    auto per_bucket{sum / k};

    // Cannot divide evenly.
    if (per_bucket * k != sum || n < k) {
      return false;
    }

    // Optimization: we tend to fill by using the biggest
    // coins available to us at first.
    std::sort(nums.rbegin(), nums.rend());

    // Optimization: short-circuit if we cannot fit an item into
    // a bucket.
    if (nums.front() > per_bucket) {
      return false;
    }

    // Optimization: reduce the search space by one element.
    // Due to this, we start i=1 in the CoinChange function.
    auto tmp{nums[0]};
    nums[0] = 0;

    return CoinChange(nums, per_bucket, k, n, tmp);
  }
};
