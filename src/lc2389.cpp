class Solution {
public:
  // Binary search over a prefix sum.
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    std::sort(nums.begin(), nums.end());

    int n(nums.size());
    std::vector<int> prefix(n + 1);
    for (int i{}; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    // Left binary search (Find rightmost element <= query).
    // We can turn this into a right binary search by inverting
    // everything.
    std::vector<int> res;
    for (auto query : queries) {
      int l{}, r{n};
      while (l < r) {
        int m{(l + r + 1) >> 1};
        if (prefix[m] <= query) {
          l = m;
        } else {
          r = m - 1;
        }
      }
      res.push_back(l);
    }
    return res;
  }
};
