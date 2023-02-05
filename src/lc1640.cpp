class Solution {
public:
  bool Dfs(std::vector<int> target, std::vector<std::vector<int>> &pieces,
           int i, std::vector<bool> &seen) {
    // Done.
    if (i == target.size()) {
      return true;
    }

    for (int j{}; j < pieces.size(); ++j) {
      if (seen[j]) {
        continue;
      }

      for (int k{}; k < pieces[j].size(); ++k) {
        if (target[i + k] != pieces[j][k]) {
          goto outer;
        }
      }

      seen[j] = true;
      if (Dfs(target, pieces, i + pieces[j].size(), seen)) {
        return true;
      }
      seen[j] = false;

    outer:;
    }
    return false;
  }

  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    std::vector<bool> seen(pieces.size(), false);
    return Dfs(arr, pieces, 0, seen);
  }
};
