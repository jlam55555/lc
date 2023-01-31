class Solution {
  struct Node {
    std::vector<int> adj;
    int indegree{};
  };

public:
  // Find the nodes that are farthest from the outside.
  // I guess this is sort of a topological sort? Where we want
  // to find the last "layer" of an undirected acyclic graph.
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    // Special case. No nodes have indegree so this has to be
    // handled specially.
    if (n == 1) {
      return {0};
    }

    // Generate graph.
    std::vector<Node> g(n);
    for (const auto &edge : edges) {
      auto n1{edge[0]}, n2{edge[1]};
      g[n1].adj.push_back(n2);
      g[n2].adj.push_back(n1);
      ++g[n1].indegree;
      ++g[n2].indegree;
    }

    // Get all indegree zero nodes.
    // (I.e., they only have one connection.)
    std::list<int> ind0{}, prev_ind0{};
    for (int i{}; i < n; ++i) {
      if (g[i].indegree == 1) {
        ind0.push_back(i);
      }
    }

    // Toposort. Save the previous set of indegree-zero nodes.
    while (!ind0.empty()) {
      prev_ind0 = std::move(ind0);
      for (const auto &n1 : prev_ind0) {
        for (auto &n2 : g[n1].adj) {
          if (--g[n2].indegree == 1) {
            ind0.push_back(n2);
          }
        }
      }
    }
    return std::vector(prev_ind0.begin(), prev_ind0.end());
  }
};
