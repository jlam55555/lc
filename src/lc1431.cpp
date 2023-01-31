class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    auto m{INT_MIN};
    for (auto i : candies) {
      m = std::max(m, i);
    }

    std::vector<bool> res(candies.size());
    for (auto i{0}; i < candies.size(); ++i) {
      res[i] = candies[i] + extraCandies >= m;
    }
    return res;
  }
};
