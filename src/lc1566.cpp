class Solution {
public:
  bool containsPattern(std::vector<int> &arr, int m, int k) {
    int N(arr.size());
    for (int i{}; i <= N - m * k; ++i) {
      for (int j{}; j < k; ++j) {
        for (int l{}; l < m; ++l) {
          if (arr[i + l] != arr[i + j * m + l]) {
            goto outer;
          }
        }
      }
      return true;
    outer:;
    }
    return false;
  }
};
