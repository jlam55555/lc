class Solution {
public:
  string categorizeBox(int l, int w, int h, int m) {
    long v{(long)l * w * h};
    bool bulky{}, heavy{};
    if (l >= 10000 || w >= 10000 || h >= 10000 || v >= 1000000000) {
      bulky = true;
    }
    if (m >= 100) {
      heavy = true;
    }
    if (bulky && heavy) {
      return "Both";
    }
    if (!bulky && !heavy) {
      return "Neither";
    }
    if (bulky) {
      return "Bulky";
    }
    return "Heavy";
  }
};
