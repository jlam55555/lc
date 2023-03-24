// DFS from city 0 outwards; if there is only an outgoing connection,
// reverse its direction.
class Solution {
  struct Edge {
    int to;
    bool out;
  };

  struct Node {
    std::vector<Edge> adj;
    bool seen{};
  };

public:
  int minReorder(int n, vector<vector<int>> &connections) {
    std::vector<Node> g(n);
    for (const auto &e : connections) {
      g[e[0]].adj.push_back({e[1], true});
      g[e[1]].adj.push_back({e[0], false});
    }

    int res{};
    std::stack<int> s;
    s.push(0);
    while (!s.empty()) {
      auto &node{g[s.top()]};
      s.pop();

      if (node.seen) {
        continue;
      }
      node.seen = true;

      for (auto &e : node.adj) {
        if (g[e.to].seen) {
          continue;
        }
        res += e.out;
        s.push(e.to);
      }
    }
    return res;
  }
};
