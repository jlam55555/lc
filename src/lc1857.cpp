// Idea: for each node, store the best result for each path
// (ending at that node) for each color. This is a good example
// of a DP+toposort question, i.e., using toposort on an
// acyclic graph to determine the DP order.
//
// Using a topological sort, we can:
// - Process all of node i's ancestors before processing node i.
// - Detect loops.
//
// With this we can easily compute the possible the best result
// for all paths ending at a node.
//
// My solution converged very closely to the editorial's solution.
//
// The editorial also points out that we can do the same with
// a DFS, which does the same in reverse (precomputes the best
// result for all paths _beginning_ at a node).
class Solution {
  struct Node {
    int indegree;
    std::vector<int> adj;
  };
  int visited_{};

public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    // Build graph.
    int n(colors.length());
    std::vector<Node> g(n);
    for (const auto &e : edges) {
      g[e[0]].adj.push_back(e[1]);
      ++g[e[1]].indegree;
    }

    // Toposort.
    std::stack<int> curr, next;
    for (int i{}; i < n; ++i) {
      if (!g[i].indegree) {
        curr.push(i);
      }
    }

    // dp indexed by [i][char]
    std::vector<std::array<int, 26>> dp(n);
    int res{};
    while (!curr.empty()) {
      while (!curr.empty()) {
        auto i{curr.top()};
        curr.pop();

        // Update best paths going through node to include node.
        res = std::max(res, ++dp[i][colors[i] - 'a']);

        // Update neighbors.
        for (auto j : g[i].adj) {
          for (int c{}; c < 26; ++c) {
            dp[j][c] = std::max(dp[j][c], dp[i][c]);
          }
          if (!--g[j].indegree) {
            next.push(j);
          }
        }
        ++visited_;
      }
      std::swap(curr, next);
    }

    // If not all nodes were visited, then we have a loop.
    return visited_ == n ? res : -1;
  }
};
