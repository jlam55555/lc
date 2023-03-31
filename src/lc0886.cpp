// Bipartite graph coloring problem. Try to color connected
// nodes with alternating colors; if we succeed, then we
// have a bipartite graph.
class Solution {
  struct Node {
    std::vector<int> adj;
    int color{};
  };

public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    // Graph building.
    std::vector<Node> g(n);
    for (const auto &e : dislikes) {
      g[e[0] - 1].adj.push_back(e[1] - 1);
      g[e[1] - 1].adj.push_back(e[0] - 1);
    }

    // Graph coloring.
    std::stack<Node *> stk;
    for (int i{}; i < n; ++i) {
      if (g[i].adj.empty() || g[i].color) {
        continue;
      }

      // Color connected neighbors.
      g[i].color = 1;
      stk.push(&g[i]);
      while (!stk.empty()) {
        auto *node{stk.top()};
        stk.pop();
        auto next_color{3 - node->color};
        for (auto n : node->adj) {
          if (!g[n].color) {
            g[n].color = next_color;
            stk.push(&g[n]);
          } else if (g[n].color != next_color) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
