class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int> &group_sizes) {
    int n(group_sizes.size());
    std::vector<int> last_size(n + 1, -1);
    std::vector<std::vector<int>> res;
    for (int i{}; i < n; ++i) {
      // Find group of this size.
      auto &last_of_size{last_size[group_sizes[i]]};

      // No group of this size, create one.
      if (last_of_size == -1) {
        last_of_size = res.size();
        res.push_back({});
      }

      // Insert into group of this size.
      res[last_of_size].push_back(i);

      // If the group is the right size, remove it.
      if (res[last_of_size].size() == group_sizes[i]) {
        last_of_size = -1;
      }
    }
    return res;
  }
};
