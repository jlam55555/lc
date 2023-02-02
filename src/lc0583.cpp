class Solution {
  using DP = std::vector<std::vector<int>>;
  static constexpr int NOT_FOUND = INT_MAX;

public:
  int minDistance(std::string_view w1, std::string_view w2, int a, int b,
                  DP &dp) {
    if (dp[a][b] != NOT_FOUND) {
      return dp[a][b];
    }

    int del{}, i{a}, j{b};
    while (i < w1.size() && j < w2.size()) {
      if (w1[i] == w2[j]) {
        ++i;
        ++j;
      } else {
        return dp[a][b] = 1 + std::min(minDistance(w1, w2, i, j + 1, dp),
                                       minDistance(w1, w2, i + 1, j, dp));
      }
    }

    // If we've reached this point, then that means that one string is a
    // substring of the other. Delete the remaining characters.
    del += w1.size() - i;
    del += w2.size() - j;

    return dp[a][b] = del;
  }

  // DP problem. If the letters are the same, advance both pointers.
  // If they are not the same, try deleting one from either the left
  // or the right position. The DP array holds the minimum
  int minDistance(string word1, string word2) {
    DP dp(word1.size() + 1, std::vector<int>(word2.size() + 1, NOT_FOUND));
    return minDistance(word1, word2, 0, 0, dp);
  }
};
