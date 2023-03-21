// This problem is fascinating and frustrating. I remember I
// encountered this problem the first time with a friend, and
// we couldn't figure it out, so we looked at the answer.
//
// Now, the second time I encounter this problem (because it
// appears that I didn't solve it the first time we looked at
// the solution) about a year later, the problem looked familiar
// to me but I still could not figure out how to solve it. I
// attempted something with a topological sort to generate
// a dependency graph of sorts, but this didn't totally work.
// I had to look at the official solution (editorial) again,
// had a brief moment of realization, and then was able to
// type out the entire solution fairly fluidly.
//
// The intuition behind the solution is based on a very clever
// trick: with each hit (assuming we hit a brick and not air),
// we may dislodge a piece of the bricks from the top group
// of bricks. We do this repeatedly. The problem is that we
// don't have an efficient data structure to track this series
// of dislodgements, but we do have an efficient data structure
// to capture the merging of disjoint sets.
//
// Thus, we take the series of hits in reverse by "filling in"
// the bricks in reverse order, and merging together any
// islands that may have been joined by the added brick. This
// is then a fabulous case study in the union-find algorithm.
//
// I use a very simple implementation of union-find here, and
// there may be chance for optimization there.
class Solution {
  class UnionFind {

    std::vector<int> grp_;
    std::vector<int> grp_size_;

  public:
    UnionFind(int n) : grp_(n), grp_size_(n, 1) {
      for (int i{}; i < n; ++i) {
        grp_[i] = i;
      }
    }
    void Union(int g1, int g2) {
      g1 = Find(g1), g2 = Find(g2);

      // Already part of the same group.
      if (g1 == g2) {
        return;
      }

      // Find the larger group; this will become the new root.
      auto size1{grp_size_[g1]}, size2{grp_size_[g2]};
      if (size1 > size2) {
        grp_[g2] = g1;
        grp_size_[g1] = size1 + size2;
      } else {
        grp_[g1] = g2;
        grp_size_[g2] = size1 + size2;
      }
    }
    int Find(int g) {
      // Path halving.
      while (grp_[g] != g) {
        g = grp_[g] = grp_[grp_[g]];
      }
      return g;
    }
    int Size(int g) { return grp_size_[Find(g)]; };
  };

public:
  std::vector<int> hitBricks(std::vector<std::vector<int>> &grid,
                             vector<vector<int>> &hits) {
    int m(grid.size()), n(grid[0].size()), h(hits.size());

    // Keep track of whether each hit actually hits a brick
    // or not (as opposed to an air space).
    std::vector<bool> is_hit;

    // Generate grid after all the hits.
    for (const auto &hit : hits) {
      int i{hit[0]}, j{hit[1]};
      is_hit.push_back(grid[i][j]);
      grid[i][j] = 0;
    }

    // Union-find on the grid. Note that we have an extra
    // group, used to mark the group of bricks at the top.
    // This lies at index `top_group == m*n`. This trick is
    // borrowed from the editorial.
    UnionFind uf{m * n + 1};
    int top_group{m * n};
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        if (!grid[i][j]) {
          continue;
        }
        // Merge with brick on top.
        if (i && grid[i - 1][j]) {
          uf.Union(i * n + j, (i - 1) * n + j);
        } else if (!i) {
          uf.Union(i * n + j, top_group);
        }
        // Merge with brick on left.
        if (j && grid[i][j - 1]) {
          uf.Union(i * n + j, i * n + (j - 1));
        }
      }
    }

    // Traverse hits in reverse order.
    std::vector<int> res(h);
    auto top_group_size{uf.Size(top_group)};
    for (int k{h - 1}; k >= 0; --k) {
      // We hit air.
      if (!is_hit[k]) {
        continue;
      }

      // Re-insert the brick, union with adjacent bricks.
      int i{hits[k][0]}, j{hits[k][1]};
      grid[i][j] = 1;
      if (i && grid[i - 1][j]) {
        uf.Union(i * n + j, (i - 1) * n + j);
      } else if (!i) {
        uf.Union(i * n + j, top_group);
      }
      if (i < m - 1 && grid[i + 1][j]) {
        uf.Union(i * n + j, (i + 1) * n + j);
      }
      if (j && grid[i][j - 1]) {
        uf.Union(i * n + j, i * n + (j - 1));
      }
      if (j < n - 1 && grid[i][j + 1]) {
        uf.Union(i * n + j, i * n + (j + 1));
      }

      // If the current brick is in the top group, then
      // we subtract one from the result, since we don't
      // count this as a fallen brick.
      auto new_top_group_size{uf.Size(top_group)};
      res[k] = new_top_group_size - top_group_size -
               (uf.Find(i * n + j) == uf.Find(top_group));
      top_group_size = new_top_group_size;
    }

    return res;
  }
};
