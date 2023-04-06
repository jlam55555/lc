// Sounds like a bin-packing problem off the bat.
// The input size is small enough that we could definitely
// brute force the solution.
//
// Use two optimizations to improve the search:
// - Short-circuit if we know the current unfairness is worse
//   than the minimum unfairness.
// - Reduce the search space by one, similar to lc0698.cpp
//   (Partition to K Equal Subsets).
class Solution {
public:
  int Unfairness(const std::vector<int> &children) {
    return *std::max_element(children.begin(), children.end());
  }

  void Dfs(const std::vector<int> &cookies, std::vector<int> &children, int i,
           int &res) {
    if (i == cookies.size()) {
      res = std::min(res, Unfairness(children));
      return;
    }

    // Try distributing cookies[i] to each child.
    for (auto &child : children) {
      // Optimization. Short circuit if we're not doing better.
      if (child + cookies[i] >= res) {
        continue;
      }
      child += cookies[i];
      Dfs(cookies, children, i + 1, res);
      child -= cookies[i];
    }
  }

  int distributeCookies(vector<int> &cookies, int k) {
    std::vector<int> children(k);
    int res{INT_MAX};
    // Optimization: reduce search space by fixing the first cookie.
    children[0] = cookies[0];
    Dfs(cookies, children, 1, res);
    return res;
  }
};
