class Solution {
public:
  // patience sort for longest increasing subsequence
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp{};
    int piles = 0;

    for (auto &i : nums) {

      // standard binary search to find first position
      // greater than or equal to i
      int l = 0, r = piles, m;
      while (l < r) {
        m = (l + r) / 2;
        if (dp[m] < i) {
          l = m + 1;
        } else {
          r = m;
        }
      }

      if (l == piles) {
        ++piles;
        dp.push_back(0);
      }
      dp[l] = i;
    }

    return piles;
  }
};
