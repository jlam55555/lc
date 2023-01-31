class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> res;
    std::vector<int> stk{0};
    int sum{};
    while (!stk.empty()) {
      // Advance.
      ++stk.back();
      ++sum;

      if (stk.back() > 9) {
        // Too large, backtrack.
        sum -= stk.back();
        stk.pop_back();
      } else if (stk.size() == k) {
        // Done, backtrack.
        if (sum == n) {
          res.push_back(stk);
        }
      } else {
        // All good, extend.
        stk.push_back(stk.back());
        sum += stk.back();
      }
    }
    return res;
  }
};
