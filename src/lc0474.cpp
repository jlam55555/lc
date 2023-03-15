#define DP_NOT_SET static_cast<uint8_t>(-1)

// This is the 2-D 0-1 knapsack problem.
// We can't do any better than a brute-force search.
class Solution {
  // Memoization: key is (i, sum1, sum2).
  // We could use a dynamically-sized array using std::vector
  // or std::calloc, but this seems to be faster and smaller.
  static uint8_t dp_[601][101][101];

public:
  // Brute force solution. Try the whole power set.
  // Returns the maximum count of elements that can be
  // fit into the knapsack considering the previous elements.
  int Dfs(std::vector<std::pair<int, int>> &zero_ones, int lim1, int lim2,
          int i, int sum1, int sum2) {
    // Memoization.
    if (dp_[i][sum1][sum2] != DP_NOT_SET) {
      return dp_[i][sum1][sum2];
    }

    // Can't add any more elements.
    if (i == zero_ones.size() || sum1 == lim1 && sum2 == lim2) {
      return dp_[i][sum1][sum2] = 0;
    }

    // Maximum not including this element.
    int res{Dfs(zero_ones, lim1, lim2, i + 1, sum1, sum2)};

    // Maximum including this element.
    auto [zeros, ones]{zero_ones[i]};
    if (zeros + sum1 <= lim1 && ones + sum2 <= lim2) {
      res = std::max(res, 1 + Dfs(zero_ones, lim1, lim2, i + 1, zeros + sum1,
                                  ones + sum2));
    }

    return dp_[i][sum1][sum2] = res;
  }

  int findMaxForm(vector<string> &strs, int m, int n) {
    // Consolidate into a more useful data structure.
    std::vector<std::pair<int, int>> zero_ones;
    for (const auto &s : strs) {
      int zeros{}, ones{};
      for (char c : s) {
        ++(c == '0' ? zeros : ones);
      }
      zero_ones.push_back({zeros, ones});
    }

    // Reset dp_.
    std::memset(dp_, DP_NOT_SET, sizeof(dp_));

    // Brute-force search.
    return Dfs(zero_ones, m, n, 0, 0, 0);
  }
};

// Avoid linker failure.
uint8_t Solution::dp_[601][101][101];
