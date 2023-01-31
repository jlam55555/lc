class Solution {
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    std::set a2(arr2.begin(), arr2.end());
    auto a2begin{a2.begin()}, a2end{a2.end()};
    auto res{0};
    for (auto i : arr1) {
      auto it{a2.lower_bound(i)};
      if (it == a2end) {
        --it;
      }
      auto v1{*it};

      it = a2.upper_bound(i);
      if (it != a2begin) {
        --it;
      }
      auto v2{*it};

      res += !(std::abs(i - v1) <= d || std::abs(i - v2) <= d);
    }
    return res;
  }
};
