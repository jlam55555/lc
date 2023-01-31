class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    auto prevMax{-1};
    for (auto i{int(arr.size() - 1)}; i >= 0; --i) {
      auto n{arr[i]};
      arr[i] = prevMax;
      prevMax = std::max(prevMax, n);
    }
    return arr;
  }
};
