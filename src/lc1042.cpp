// Easy graph coloring problem: choose a number that isn't
// chosen by any of its neighbors.
//
// Note that when building a graph, we only add smaller
// nodes to the adjacency list of the larger node, because
// the larger node hasn't been colored yet.
class Solution {
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    std::vector<int> res(n);
    std::vector<std::vector<int>> g(n);
    for (const auto &e : paths) {
      g[std::max(e[0], e[1]) - 1].push_back(std::min(e[0], e[1]) - 1);
    }
    for (int i{}; i < n; ++i) {
      std::array<bool, 4> seen{};
      for (auto j : g[i]) {
        seen[res[j] - 1] = true;
      }
      for (int j{1}; j <= 4; ++j) {
        if (!seen[j - 1]) {
          res[i] = j;
          break;
        }
      }
    }
    return res;
  }
};
