class Solution {
public:
  bool canPlaceFlowers(const vector<int> &flowerbed, int n) {
    // Edge case.
    if (!n) {
      return true;
    }
    // Try to place flowers at i.
    for (auto i{0}, l{int(flowerbed.size())}; i < l; i += 2) {
      if (i < l - 1 && flowerbed[i + 1]) {
        ++i;
      } else if (!flowerbed[i] && !--n) {
        return true;
      }
    }
    return false;
  }
};
