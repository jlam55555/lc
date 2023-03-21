// We simply carry out the formula provided, making each element
// the highest it possibly can be.
class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i{1}, n(arr.size()); i < n; ++i) {
      arr[i] = std::min(arr[i], arr[i - 1] + 1);
    }
    return arr.back();
  }
};
