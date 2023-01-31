class Solution {
public:
  // Find the largest connected subgraph using dfs.
  int removeStones(const vector<vector<int>> &stones) {
    // Create adjacency graph.
    std::vector<std::vector<int>> g(stones.size());
    g.reserve(stones.size());
    std::unordered_map<int, std::vector<int>> rows, cols;
    for (auto i{0}; i < stones.size(); ++i) {
      rows[stones[i][0]].push_back(i);
      cols[stones[i][1]].push_back(i);
    }
    for (auto i{0}; i < stones.size(); ++i) {
      for (auto j : rows[stones[i][0]]) {
        if (j != i) {
          g[i].push_back(j);
        }
      }
      for (auto j : cols[stones[i][1]]) {
        if (j != i) {
          g[i].push_back(j);
        }
      }
    }

    // Dfs this thing.
    auto removals{0};
    std::vector<bool> seen(g.size());
    for (auto i{0}; i < stones.size(); ++i) {
      auto subgraph_size{Dfs(i, g, seen)};
      if (subgraph_size) {
        removals += subgraph_size - 1;
      }
    }
    return removals;
  }

  int Dfs(int i, const std::vector<std::vector<int>> &g,
          std::vector<bool> &seen) {
    if (seen[i]) {
      return 0;
    }
    seen[i] = true;

    auto subgraph_size{0};
    for (auto j : g[i]) {
      subgraph_size += Dfs(j, g, seen);
    }
    return subgraph_size + 1;
  }
};
