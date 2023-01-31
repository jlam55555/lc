class Solution {
public:
  bool IsSelfDividing(int i) {
    auto n = i;
    while (i) {
      if (!(i % 10)) {
        return false;
      }
      if (n % (i % 10)) {
        return false;
      }
      i /= 10;
    }
    return true;
  }

  vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> res;
    for (auto i{left}; i <= right; ++i) {
      if (IsSelfDividing(i)) {
        res.push_back(i);
      }
    }
    return res;
  }
};
