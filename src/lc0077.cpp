class Solution {
public:
  // Copying solution from top answer, it is pretty neat.
  vector<vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> cur(k);

    int i{};
    while (i >= 0) {
      // Advance.
      ++cur[i];
      // Current number too large, backtrack.
      if (cur[i] > n) {
        --i;
      }
      // Reached the end, found a solution.
      else if (i == k - 1) {
        res.push_back(cur);
      }
      // Continue to next position.
      else {
        cur[i + 1] = cur[i];
        ++i;
      }
    }

    return res;
  }
};
