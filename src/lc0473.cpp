// As mentioned in @Mazhar_MIK's comment on the editorial, this is a
// variant of the bin-packing problem and equivalent to lc0698.cpp
// where k=4. I follow the same approach as that solution.
//
// See also lc1655.cpp, which is also a bin-packing variant.
class Solution {
public:
  // Optimization: bucket_i parameter prevents us from trying to add
  // the same elements to the bucket multiple times. Inspired by
  // @Mazhar_MIK's solution (in the editorial comments). We start with
  // bucket_i=1 by default since we always put the first element in
  // the first group to reduce the search space (see lc0698.cpp).
  bool Dfs(const std::vector<int> &matches, int n, int bucket_sum, int &seen,
           int buckets, int current_sum, int bucket_i = 1) {
    // Found a valid solution.
    if (buckets == 3) {
      return true;
    }

    // Finished a bucket.
    if (current_sum == bucket_sum) {
      return Dfs(matches, n, bucket_sum, seen, buckets + 1, 0);
    }

    // Iterate over remaining items.
    for (int mask{1 << bucket_i}; bucket_i < n; ++bucket_i, mask <<= 1) {
      if (seen & mask || current_sum + matches[bucket_i] > bucket_sum) {
        continue;
      }
      seen |= mask;
      if (Dfs(matches, n, bucket_sum, seen, buckets,
              current_sum + matches[bucket_i], bucket_i + 1)) {
        return true;
      }
      seen &= ~mask;
    }
    return false;
  }

  // To choose three sides worth of matchsticks, we can count
  // the number of options:
  // nC3 + nC4 + ... + nC(n-1)
  // = 2^n - (nC0 + nC1 + nC2 + nCn)
  // = 2^n - (1 + 2n + n(n-1)/2)
  // Which is not a huge number. So we can do a backtracking
  // search. (We could also probably enumerate using something
  // like https://stackoverflow.com/a/506862/2397327, but it would
  // be a little tricky to partition into three groups.)
  bool makesquare(vector<int> &matchsticks) {
    int sum{std::accumulate(matchsticks.begin(), matchsticks.end(), 0)},
        n(matchsticks.size());

    // Need to make four buckets of size sum/4.
    int bucket{sum >> 2};

    // Optimization: be a little greedy by trying to fit bigger
    // matches first. See lc0698.cpp.
    std::sort(matchsticks.rbegin(), matchsticks.rend());

    // Optimization: reduce the search space by 1.
    // See lc0698.cpp.
    int seen{1 << 0};
    int curr_sum{matchsticks[0]};

    // Optimization: Remove the obvious failing cases.
    // See lc0698.cpp.
    if (sum % 4 || n < 4 || matchsticks[0] > bucket) {
      return false;
    }

    return Dfs(matchsticks, n, bucket, seen, 0, curr_sum);
  }
};
