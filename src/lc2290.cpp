// Idea: iteratively compute the set of cells that we
// can reach without traversing any wayys, the set of
// cells that we can reach after traversing one wall,
// ... two walls, etc.
//
// Similar to a BFS but the current frontier is not the
// set of cells with the same depth, it's the set of
// set of cells that are reachable with the same number
// of wall-traversals.
//
// A somewhat-similar question that I recently did
// involved keeping a frontier of cells reachable with
// the same number of "diversions" from a source cell
// to a target cell, the "Hadlock algorithm" used for
// grid search (lc0675.cpp).
class Solution {
public:
  int minimumObstacles(vector<vector<int>> &grid) {
    int m(grid.size()), n(grid[0].size());

    std::vector<std::vector<bool>> seen(m, std::vector<bool>(n));

    // Current and next frontier sets. See note in
    // lc0675.cpp about the choice of std::stack.
    std::stack<std::pair<int, int>> curr, next;
    curr.push({0, 0});

    for (int depth{grid[0][0]};; ++depth, std::swap(curr, next)) {
      while (!curr.empty()) {
        auto [i, j]{curr.top()};
        curr.pop();

        // Already encountered.
        if (seen[i][j]) {
          continue;
        }
        seen[i][j] = true;

        // Reached the end.
        if (i == m - 1 && j == n - 1) {
          return depth;
        }

// Add elements to the current or next depth
// of the frontier. Also do a bounds check here.
#define add_to_frontier(i, j)                                                  \
  if ((i) >= 0 && (i) < m && (j) >= 0 && (j) < n && !seen[i][j])               \
    (grid[i][j] ? next : curr).push({(i), (j)});
        add_to_frontier(i + 1, j);
        add_to_frontier(i - 1, j);
        add_to_frontier(i, j + 1);
        add_to_frontier(i, j - 1);
#undef add_to_frontier
      }
    }

    throw logic_error{"shouldn't happen"};
  }
};
