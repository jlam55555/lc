class Solution {
public:
  // Wow, I could not think of a solution to this.
  //
  // The divide-and-conquer solution (see @StefanPochmann's solution)
  // is fairly intuitive in hindsight but did not come to mind when
  // I approached the problem. @StefanPochmann's solution is very
  // elegant, as always.
  //
  // The sliding-window solution given in the official solution
  // is interesting and would not be something I would think of.
  // The idea of fixing a value for the number of unique characters
  // is interesting and makes the sliding-window approach feasible.
  // As multiple comments say, this solution feels like it would be for
  // a "hard" difficulty question (but I think the divide-and-conquer
  // solution is fair for a "medium" question). This sliding window
  // approach is also used in @sniffsky's solution.
  //
  // This is the sliding-window approach. We attempt to keep
  // a window with i unique characters, where 1<=i<=26. This has
  // time complexity O(26*n) = O(n) and space complexity
  // O(26) = O(1).
  int longestSubstring(string s, int k) {
    int n(s.length());

    if (k > n) {
      return 0;
    }

    int res{};

    // Loop over windows with `i` unique characters.
    // For each window, we keep track of two things:
    // 1. How many unique characters there are in the window.
    //    (num_unique == i unless we've reached the end of the
    //    array or if there are fewer than i unique characters
    //    in the string.)
    // 2. How many characters have a count >= k. If
    //    num_ge_k == num_unique, then this is a valid substring.
    for (int i{1}; i <= 26; ++i) {

      // Window is given by the closed interval [l, r].
      int l{}, r{}, num_unique{}, num_ge_k{};
      std::vector<int> freqs(26, 0);

      // Generate initial window of `i` unique characters.
      for (; r < n && num_unique < i; ++r) {
        if (!freqs[s[r] - 'a']++) {
          ++num_unique;
        }
        if (freqs[s[r] - 'a'] == k) {
          ++num_ge_k;
        }

        // Valid substring.
        if (num_ge_k == i) {
          res = std::max(res, r - l + 1);
        }
      }

      // There are fewer than `i` unique characters.
      // Our work is done.
      if (num_unique != i) {
        break;
      }

      // Advance the right end of the window by 1. Update
      // the left end as necessary.
      for (; r < n; ++r) {

        // Update right end.
        if (!freqs[s[r] - 'a']++) {
          ++num_unique;
        }
        if (freqs[s[r] - 'a'] == k) {
          ++num_ge_k;
        }

        // Adjust left end as necessary.
        while (l < r && num_unique > i) {
          if (!--freqs[s[l] - 'a']) {
            --num_unique;
          }
          if (freqs[s[l++] - 'a'] == k - 1) {
            --num_ge_k;
          }
        }

        // Reached the end of the string.
        if (num_unique < i) {
          break;
        }

        // Valid substring.
        if (num_ge_k == i) {
          res = std::max(res, r - l + 1);
        }
      }
    }

    return res;
  }
};
