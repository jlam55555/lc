// `powers[n]` is equal to the bits set in `n`.
class Solution {
public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    std::vector<int> powers;
    for (int mask{1}; mask <= n; mask <<= 1) {
      if (mask & n) {
        powers.push_back(mask);
      }
    }

    std::vector<int> res;
    auto pow_it{powers.begin()};
    for (const auto &query : queries) {
      res.push_back(std::accumulate(
          pow_it + query[0], pow_it + query[1] + 1, 1,
          [](auto acc, auto val) { return long(acc) * val % 1000000007; }));
    }
    return res;
  }
};
