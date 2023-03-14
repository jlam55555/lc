// Patience sort for longest increasing subsequence.
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    std::vector<int> piles;
    for (auto i : nums) {
      if (auto it{std::lower_bound(piles.begin(), piles.end(), i)};
          it != piles.end()) {
        *it = i;
      } else {
        piles.push_back(i);
      }
    }
    return piles.size();
  }
};
