// Loop through the nodes, find the highest k adjacent nodes
// or the l adjacent positive nodes (if `l < k`). Take the max.
//
// This solution works but is perhaps not the prettiest -- I tried
// to be efficient by adding reverse edges and sorting them at the
// beginning to avoid having to have an adjacency-list graph
// representation, but it looks from the top solutions that this
// is probably the easier solution.
class Solution {
public:
  int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
    int n(vals.size()), m(edges.size());

    for (int i{}; i < m; ++i) {
      edges.push_back({edges[i][1], edges[i][0]});
    }

    std::sort(edges.begin(), edges.end());

    int res{INT_MIN};
    for (int i{}, e{}; i < n; ++i) {
      int e2{e};
      while (e2 < 2 * m && edges[e2][0] <= i) {
        ++e2;
      }

      // Now there are o=(e2-e) connected to node i.
      // Then get the sum of the non-negative highest min(o, k)
      // elements.
      int o{e2 - e};
      auto it_start{edges.begin() + e}, it_end{edges.begin() + e2};
      if (o > k) {
        auto it{edges.begin() + e2 - k};
        std::nth_element(it_start, it, it_end,
                         [&](const auto &e1, const auto &e2) {
                           return vals[e1[1]] < vals[e2[1]];
                         });
        it_start = it;
      }
      auto k_neighbors_max{
          std::accumulate(it_start, it_end, 0, [&](auto acc, const auto &e) {
            return acc + std::max(0, vals[e[1]]);
          })};

      res = std::max(res, vals[i] + k_neighbors_max);
      e = e2;
    }

    return res;
  }
};
