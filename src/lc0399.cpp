// I found this problem to be really fun. It has a good mix of
// math and graphs and is fairly open-ended. It wasn't too hard
// to think of the solution once the question was understood,
// but it's not a trivial solution.
class Solution {
public:
  using VD = std::vector<double>;
  using VVS = std::vector<std::vector<std::string>>;

  // Try to find a path from `from` to `to`.
  // - If such a path is found, return the product of all
  //   edges on the path.
  // - If no such path is found, return 0.
  //
  // To prevent going in loops, we use the `visited` array.
  // We don't really need this and can mark `g` in place,
  // but this is a bit neater.
  double Dfs(const std::vector<VD> &g, std::vector<bool> &visited, int n,
             int from, int to) {

    // Note: this is the base case and also handles the
    // identity rule.
    if (from == to) {
      return 1.;
    }

    visited[from] = true;
    for (int i{}; i < n; ++i) {
      // Avoid revisiting nodes.
      if (visited[i]) {
        continue;
      }

      // Try to find a path to the target.
      if (auto edge{g[from][i]}; edge) {
        if (auto res{Dfs(g, visited, n, i, to)}; res) {
          return edge * res;
        }
      }
    }
    visited[from] = false;
    return 0.;
  }

  // Helper function.
  double Dfs(const std::vector<VD> &g, int from, int to) {
    int n(g.size());
    std::vector<bool> visited(n, false);
    return Dfs(g, visited, n, from, to);
  }

  // Rules of division:
  // C/C=1                    // identity rule
  // C/D=X => C/D=X           // query given as rule
  // D/C=X => C/D=1/X         // query given as rule inverse
  // C/A=X, A/D=Y => C/D=XY   // transitive rule
  //
  // We basically are trying to find a path between C_i and D_i,
  // and apply these rules down that path. We build a graph
  // and then DFS it.
  VD calcEquation(VVS &equations, VD &values, VVS &queries) {
    // Generate mapping from variables to indices.
    std::unordered_map<std::string, int> vars;
    int n{};
    for (const auto &eq : equations) {
      auto &v1{eq[0]}, &v2{eq[1]};
      if (!vars.count(v1)) {
        vars[v1] = n++;
      }
      if (!vars.count(v2)) {
        vars[v2] = n++;
      }
    }

    // Generate graph. This could have been done in the above
    // step, but it is more efficient to create the graph all
    // at once here. Since there cannot be that many variables
    // (at most 2*20 = 40 variables) we use an array to
    // (hopefully) be more time and space efficient.
    //
    // g[vars[A]][vars[B]] represents A/B, or 0 if unknown.
    std::vector<VD> g(n, VD(n));
    for (int i{}; i < equations.size(); ++i) {
      const auto &v1{equations[i][0]}, v2{equations[i][1]};
      auto val{values[i]};
      g[vars[v1]][vars[v2]] = values[i];
      g[vars[v2]][vars[v1]] = 1. / values[i];
    }

    // Handle queries.
    VD res;
    for (auto query : queries) {
      const auto &v1{query[0]}, &v2{query[1]};

      // Variable(s) not found.
      if (!vars.count(v1) || !vars.count(v2)) {
        res.push_back(-1.);
        continue;
      }

      // Variables found, look for a path between them.
      auto quotient{Dfs(g, vars[v1], vars[v2])};
      res.push_back(quotient ? quotient : -1.);
    }
    return res;
  }
};
