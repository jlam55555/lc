class Solution {
public:
  // Assumes n is nonzero
  bool HasZero(int n) {
    while (n) {
      if (!(n % 10)) {
        return true;
      }
      n /= 10;
    }
    return false;
  }

  vector<int> getNoZeroIntegers(int n) {
    for (auto i{1};; ++i) {
      auto j{n - i};
      if (!HasZero(i) && !HasZero(j)) {
        return {i, j};
      }
    }
    throw logic_error{"shouldn't happen"};
  }
};
