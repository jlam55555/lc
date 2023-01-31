class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    auto l{int(arr.size())};
    auto q{l >> 2};
    for (auto i{0}; i < arr.size() - q; ++i) {
      if (arr[i] == arr[i + q]) {
        return arr[i];
      }
    }
    return arr[0];
  }
};
