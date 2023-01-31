class Solution {
public:
  // Cheating here with std::swap.
  void duplicateZeros(vector<int> &arr) {
    std::vector<int> res(arr.size());
    for (auto i{0}, j{0}; j < arr.size();) {
      if (arr[i] == 0) {
        ++i;
        res[j++] = 0;
        if (j < arr.size()) {
          res[j++] = 0;
        }
      } else {
        res[j++] = arr[i++];
      }
    }
    std::swap(arr, res);
  }
};
