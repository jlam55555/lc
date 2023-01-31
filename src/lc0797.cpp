typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

class Solution {
public:
  //     vvi dfs(vvi& graph, vvvi& dp, int node) {
  //         // memoized results
  //         if (!dp[node].empty()) {
  //             return dp[node];
  //         }

  //         if (node == graph.size()-1) {
  //             return dp[node] = {{node}};
  //         }

  //         vvi res{};
  //         for (int adj : graph[node]) {
  //             vvi subPaths = dfs(graph, dp, adj);
  //             for (int i = 0; i < subPaths.size(); ++i) {
  //                 subPaths[i].push_back(node);
  //             }
  //             res.insert(res.end(), subPaths.begin(), subPaths.end());
  //         }
  //         return dp[node] = res;
  //     }

  //     vvi allPathsSourceTarget(vvi& graph) {
  //         vvvi dp(graph.size());
  //         vvi paths = dfs(graph, dp, 0);

  //         // reverse all the things
  //         for (int i = 0; i < paths.size(); ++i) {
  //             reverse(paths[i].begin(), paths[i].end());
  //         }

  //         return paths;
  //     }

  void dfs(vvi &graph, vvi &res, vi &stk, int node) {
    stk.push_back(node);

    if (node == graph.size() - 1) {
      res.push_back(stk);
    } else {
      for (int adj : graph[node]) {
        dfs(graph, res, stk, adj);
      }
    }

    stk.pop_back();
  }

  vvi allPathsSourceTarget(vvi &graph) {
    vvi res{};
    vi stk{};
    dfs(graph, res, stk, 0);
    return res;
  }
};
