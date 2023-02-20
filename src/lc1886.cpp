class Solution {
public:
  bool findRotation(std::vector<std::vector<int>> &mat,
                    std::vector<std::vector<int>> &target) {
    bool deg0{}, deg90{}, deg180{}, deg270{};
    int n(mat.size());

    for (int i{}; i < n; ++i) {
      for (int j{}; j < n; ++j) {
        deg0 |= mat[i][j] != target[i][j];
        deg90 |= mat[i][j] != target[j][n - 1 - i];
        deg180 |= mat[i][j] != target[n - 1 - i][n - 1 - j];
        deg270 |= mat[i][j] != target[n - 1 - j][i];

        // Short-circuit.
        if (deg0 && deg90 && deg180 && deg270) {
          return false;
        }
      }
    }

    return true;
  }
};
