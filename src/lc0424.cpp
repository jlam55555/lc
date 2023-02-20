class Solution {
public:
  // Sliding window approach. Find the length of the longest window
  // containing (at most) `k` characters that are not `c`.
  int characterReplacement(const std::string_view s, int k, char c) {
    int n(s.length()), l{}, r{}, non_c{}, res{};

    // The window is [l, r] (inclusive).
    for (; r < n; ++r) {
      if (s[r] != c) {
        ++non_c;
      }

      while (non_c > k && l < r) {
        if (s[l++] != c) {
          --non_c;
        }
      }

      res = std::max(res, r - l + 1);
    }

    return res;
  }

  // Initial thoughts:
  // - Clearly we only want to change letters to the same letter,
  //   otherwise we'd be fighting ourselves. We can try looping over
  //   each letter and trying to find the longest substring out of it.
  int characterReplacement(string s, int k) {
    int res{};
    for (char c{'A'}; c <= 'Z'; ++c) {
      res = std::max(res, characterReplacement(s, k, c));
    }
    return res;
  }
};
