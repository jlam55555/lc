class Solution {
public:
  // Returns the number of hours to finish eating at speed k.
  int Hours(const std::vector<int> &piles, int k) {
    int res{};
    for (auto pile : piles) {
      res += (pile + (k - 1)) / k;
    }
    return res;
  }

  // Binary search over the solution space.
  int minEatingSpeed(vector<int> &piles, int h) {
    int l{1}, r{*std::max_element(piles.begin(), piles.end())};
    while (l < r) {
      int m{(l + r) / 2};
      if (Hours(piles, m) <= h) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
