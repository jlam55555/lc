class Solution {
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int l = arr.size(), res{};
    for (int i = 0; i < l; ++i) {
      for (int j = i + 1; j < l; ++j) {
        for (int k = j + 1; k < l; ++k) {
          res += std::abs(arr[i] - arr[j]) <= a &&
                 std::abs(arr[j] - arr[k]) <= b &&
                 std::abs(arr[k] - arr[i]) <= c;
        }
      }
    }
    return res;
  }
};
