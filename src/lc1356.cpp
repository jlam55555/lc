class Solution {
public:
  int SetBits(int n) {
    auto res{0};
    while (n) {
      n &= n - 1;
      ++res;
    }
    return res;
  }

  vector<int> sortByBits(vector<int> &arr) {
    std::vector<std::vector<int>> a;
    for (auto i : arr) {
      a.push_back({SetBits(i), i});
    }

    std::sort(a.begin(), a.end());

    for (auto i{0}; i < arr.size(); ++i) {
      arr[i] = a[i][1];
    }
    return arr;
  }
};
