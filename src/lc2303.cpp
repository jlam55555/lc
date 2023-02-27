class Solution {
public:
  double calculateTax(vector<vector<int>> &brackets, int income) {
    double res{};
    int prev{};
    for (const auto &bracket : brackets) {
      // Short circuit.
      if (!income) {
        return res;
      }
      auto upper{bracket[0]}, pct{bracket[1]},
          amt{std::min(upper - prev, income)};
      income -= amt;
      prev = upper;
      res += (double)pct / 100 * amt;
    }
    return res;
  }
};
