// Algorithm:
// - Union-find to group nodes.
// - Count how many pairs can be formed with each group. For
//   a group with size g, we can form g*(n-g) pairs with it
//   (choosing one number from this group and one from
//   outside this group).
class Solution {
  class UnionFind {
    std::vector<int> groups_;
    std::vector<int> grp_size_;

  public:
    UnionFind(int n) : groups_(n), grp_size_(n, 1) {
      for (int i{}; i < n; ++i) {
        groups_[i] = i;
      }
    }
    void Union(int g1, int g2) {
      if ((g1 = Find(g1)) == (g2 = Find(g2))) {
        return;
      }
      auto size1{grp_size_[g1]}, size2{grp_size_[g2]};
      if (size1 > size2) {
        groups_[g2] = g1;
        grp_size_[g1] += size2;
      } else {
        groups_[g1] = g2;
        grp_size_[g2] += size1;
      }
    }
    int Find(int g) {
      while (groups_[g] != g) {
        g = groups_[g] = groups_[groups_[g]];
      }
      return g;
    }
    std::vector<int> GroupSizes() {
      std::vector<int> res;
      for (int i{}, n(groups_.size()); i < n; ++i) {
        if (groups_[i] == i) {
          res.push_back(grp_size_[i]);
        }
      }
      return res;
    }
  };

public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    UnionFind uf{n};

    for (const auto &e : edges) {
      uf.Union(e[0], e[1]);
    }

    auto grp_sizes{uf.GroupSizes()};
    return std::accumulate(
               grp_sizes.begin(), grp_sizes.end(), 0ll,
               [n](auto acc, auto g) { return acc + g * long(n - g); }) /
           2;
  }
};
