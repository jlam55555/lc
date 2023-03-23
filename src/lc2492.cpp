// This is kind of a silly question. We basically need
// to find the lowest-cost road that is reachable from
// the current point, because we're always allowed to
// backtrack. We can do this with a simple DFS.
class Solution {
  struct Edge {
    int to, val;
  };

  struct Node {
    std::vector<Edge> adj;
    bool seen;
  };

public:
  int minScore(int n, vector<vector<int>> &roads) {
    // Build graph.
    std::vector<Node> g(n);
    for (const auto &e : roads) {
      g[e[0] - 1].adj.push_back({e[1] - 1, e[2]});
      g[e[1] - 1].adj.push_back({e[0] - 1, e[2]});
    }

    // DFS to find the minimum edge connected to
    // the first and last nodes.
    std::stack<Node *> stk;
    stk.push(&g.front());
    int res{INT_MAX};
    while (!stk.empty()) {
      auto *node{stk.top()};
      stk.pop();
      if (node->seen) {
        continue;
      }
      node->seen = true;
      for (const auto &e : node->adj) {
        res = std::min(res, e.val);
        if (!g[e.to].seen) {
          stk.push(&g[e.to]);
        }
      }
    }
    return res;
  }
};
