class Solution {
  // Returns sum({ 1, 2, ..., n }).
  static inline int sum_to(int n) { return n * (n + 1) >> 1; }

public:
  // Both the official solution and @meng789987's solution are pretty
  // good. Both are O(1) space and 1-pass O(N) time.
  //
  // The following solution is my adaptation of the official solution.
  // The general idea is that we add to the result at each valley,
  // and possibly at the end (if we don't finish at a valley).
  //
  // I had trouble determining the beginning of a peak or valley,
  // given that the peaks and valleys are non-strict. (I.e., it is a
  // bit tricky when adjacent elements have the same rating.) The way
  // the official solution handles it by looking at a change in slope
  // is clever -- this makes it very clear when we reach a peak or a
  // valley.
  int candy(std::vector<int> &ratings) {
    // Edge case.
    if (ratings.size() == 1) {
      return 1;
    }

    int n(ratings.size()), res{}, up{}, down{}, slope{};
    for (int i{1}; i < n; ++i) {
      auto new_slope =
          ratings[i] < ratings[i - 1] ? -1 : ratings[i] > ratings[i - 1];

      // Valley. Recognizing this condition was by far the trickiest
      // part of the solution for me. There are  four conditions here:
      //   __      \         ______       \  /
      //  /     OR  \__  OR           OR   \/
      //
      // Basically, if the slope is flat or goes from negative to
      // positive, we've found a "valley". This is because our valleys
      // are based on a non-strict comparison.
      if (!new_slope || slope < 0 && new_slope > 0) {
        auto peak{std::max(up, down) + 1};
        // Note the -1 at the end -- this is to avoid double-counting
        // valleys. In the final sum after the loop, we count the final
        // valley exactly once (there is no -1).
        res += sum_to(up) + sum_to(down) + peak - 1;
        up = down = 0;
      }

      // This part was also tricky for me to understand. If the slope is
      // positive or negative, then clearly we want to increase the
      // length of the up- or down-slope. But if the slope is zero?
      // Then we in a valley (see the condition above), so there should
      // be 1 candy at this spot. Thus we increment `res`.
      ++((slope = new_slope) ? (slope > 0 ? up : down) : res);
    }

    // Cleanup at the end if we didn't finish at a valley.
    auto peak{std::max(up, down) + 1};
    res += sum_to(up) + sum_to(down) + peak;

    return res;
  }

  // This was my original thought and passes the Leetcode scoring.
  // But it's O(N*log(N)) time and O(N) space, we can do better.
  // See the above solution.
  //
  // Algorithm: we go in sorted order of ratings to determine
  // number of candies.
  //
  // The lowest rating has one candy. If a rating is higher than
  // either of its neighbors, it means that we've already
  // determined the number of the candies for its neighbors
  // since we go in sorted order, so we give it one more candy
  // than its smaller neighbor.
  int candy_old(vector<int> &ratings) {
    int n(ratings.size());
    std::vector<int> candies(n, 1);

    // Sort the ratings, keep them paired with their indices.
    std::vector<std::pair<int, int>> sorted_ratings;
    for (int i{}; i < n; ++i) {
      sorted_ratings.push_back({ratings[i], i});
    }
    std::sort(sorted_ratings.begin(), sorted_ratings.end());

    // Greedy candy-counting algorithm.
    for (const auto &[rating, i] : sorted_ratings) {
      // Make sure we are larger than left if necessary.
      if (i && ratings[i - 1] < ratings[i]) {
        candies[i] = candies[i - 1] + 1;
      }

      // Make sure we are larger than the right if necessary.
      if (i < n - 1 && ratings[i + 1] < ratings[i]) {
        candies[i] = std::max(candies[i], candies[i + 1] + 1);
      }
    }

    // Count the candies.
    int res{};
    for (auto c : candies) {
      res += c;
    }
    return res;
  }
};
