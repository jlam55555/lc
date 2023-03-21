// General idea: given some element arr[i], this
// chunk should be at least as large as
// [arr[i], i] (if `arr[i] <= i`) or [i, arr[i]]
// (if `arr[i] >= i`).
class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    int res{};
    for (int i{}, n(arr.size()); i < n; ++res) {
      int j{i}, right{arr[i]};
      while (j <= right) {
        right = std::max(right, arr[j++]);
      }
      i = j;
    }
    return res;
  }
};
