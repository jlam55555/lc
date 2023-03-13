// See also lc0473.cpp and lc0698.cpp. These have a similar
// backtracking solution for a bin-packing variant.
class Solution {
public:
  // Standard backtracking algorithm.
  bool Dfs(std::vector<int> &bins, const std::vector<int> &queries, int i) {
    // Reached the end.
    if (i == queries.size()) {
      return true;
    }

    auto query{queries[i]};

    // Loop through the available quantities.
    for (int j{}, n(bins.size()); j < n; ++j) {
      // Cannot satisfy reqest.
      if (bins[j] < query) {
        goto continue_;
      }

      // If we've seen this before, don't repeat it.
      // We can also use a std::unordered_set, but this
      // saves a lot of space and is actually faster
      // empirically. This optimization inspired by
      // @withacup's solution to lc0473.cpp.
      for (int k{j - 1}; k >= 0; --k) {
        if (bins[k] == bins[j]) {
          goto continue_;
        }
      }

      // Can satisfy request.
      bins[j] -= query;
      if (Dfs(bins, queries, i + 1)) {
        return true;
      }
      bins[j] += query;

    // Used as a `continue` for the inner loop.
    continue_:;
    }

    return false;
  }

  bool canDistribute(vector<int> &nums, vector<int> &quantity) {
    // Bin inputs.
    std::unordered_map<int, int> freqs;
    for (auto i : nums) {
      ++freqs[i];
    }

    // Put it into an array for easier access.
    std::vector<int> bins;
    for (const auto [unused, freq] : freqs) {
      bins.push_back(freq);
    }

    // Quick check: make sure that the total quantity is sufficient.
    if (std::accumulate(bins.begin(), bins.end(), 0) <
        std::accumulate(quantity.begin(), quantity.end(), 0)) {
      return false;
    }

    // Quick check: make sure that there is a bin large enough
    // for the largest quantity. Sorting also improves locality of similar
    // items, which makes it faster to detect duplicates.
    std::sort(bins.rbegin(), bins.rend());
    if (*std::max_element(quantity.begin(), quantity.end()) > bins[0]) {
      return false;
    }

    // Attempt to distribute via standard backtracking with some optimizations.
    return Dfs(bins, quantity, 0);
  }
};
