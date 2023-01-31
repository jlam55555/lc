class Solution {
  // Join and return new root.
  int join(std::unordered_map<int, int> &groups,
           std::unordered_map<int, int> &group_sizes, int n1, int n2) {

    // Find roots. (Path halving.)
    auto it1 = n1, it2 = n2;
    while (it1 != groups[it1]) {
      groups[it1] = groups[groups[it1]];
      it1 = groups[it1];
    }
    while (it2 != groups[it2]) {
      groups[it2] = groups[groups[it2]];
      it2 = groups[it2];
    }

    // Merge to larger group.
    if (group_sizes[it1] > group_sizes[it2]) {
      groups[it2] = it1;
      group_sizes[it1] += group_sizes[it2];
      return it1;
    } else {
      groups[it1] = it2;
      group_sizes[it2] += group_sizes[it1];
      return it2;
    }
  }

public:
  // Union-find.
  int longestConsecutive(vector<int> &nums) {
    std::unordered_map<int, int> groups;
    std::unordered_map<int, int> group_sizes;
    int max_group_size{};
    for (auto n : nums) {
      // Already saw this, continue.
      if (groups.count(n)) {
        continue;
      }

      // Create new group.
      auto root = n;
      groups[root] = root;
      group_sizes[root] = 1;

      // If group on left, join with that.
      if (groups.count(n - 1)) {
        root = join(groups, group_sizes, root, n - 1);
      }

      // If group on right, join with that.
      if (groups.count(n + 1)) {
        root = join(groups, group_sizes, root, n + 1);
      }

      groups[n] = root;
      max_group_size = std::max(max_group_size, group_sizes[root]);
    }
    return max_group_size;
  }
};
