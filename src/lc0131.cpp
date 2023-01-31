using DP = std::array<std::array<bool, 16>, 17>;

class Solution {
public:
  void dfs(int j, int l, const std::string_view s, DP dp,
           std::vector<std::string> &stk,
           std::vector<std::vector<std::string>> &res) {

    if (j == l) {
      // Found a solution.
      res.push_back(stk);
      return;
    }

    for (int i{1}; i <= l - j; ++i) {
      if (!dp[j][i]) {
        continue;
      }

      stk.emplace_back(s.substr(j, i));
      dfs(j + i, l, s, dp, stk, res);
      stk.pop_back();
    }
  }

  vector<vector<string>> partition(string s) {
    // Base case.
    // dp[start][len]
    DP dp{};
    int l = s.length();
    for (int i{}; i < l; ++i) {
      dp[i][0] = dp[i][1] = true;
    }

    // Compute all palindromes.
    // `i` is length, `j` is start position.
    for (int i{2}; i <= l; ++i) {
      for (int j{0}; j <= l - i; ++j) {
        // Check if center is palindrome, and if two outsides match.
        auto center = dp[j + 1][i - 2];
        auto left = s[j];
        auto right = s[j + i - 1];
        dp[j][i] = center && (left == right);
      }
    }

    // Generate all possible partitions.
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> stk;
    dfs(0, l, s, dp, stk, res);
    return res;
  }
};

// 0 1 2
// a b a

// i = 3
// j = 0
//    v start = j+1
// dp[1][1]
//       ^ len = i-2
