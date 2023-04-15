// Straightforward backtracking DFS solution
class Solution {
public:
  void Dfs(int n, int i, int k, std::vector<int> &res) {
    if (!n) {
      res.push_back(i);
      return;
    }

    int last_dig{i % 10};
    if (last_dig + k <= 9) {
      Dfs(n - 1, i * 10 + (last_dig + k), k, res);
    }
    if (k && last_dig - k >= 0) {
      Dfs(n - 1, i * 10 + (last_dig - k), k, res);
    }
  }

  vector<int> numsSameConsecDiff(int n, int k) {
    std::vector<int> res;
    for (int i{1}; i <= 9; ++i) {
      Dfs(n - 1, i, k, res);
    }
    return res;
  }
};
