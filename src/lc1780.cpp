class Solution {
  // Generated using Python.
  static constexpr const std::array<int, 15> powers_{
      4782969, 1594323, 531441, 177147, 59049, 19683, 6561, 2187,
      729,     243,     81,     27,     9,     3,     1};

public:
  bool checkPowersOfThree(int n) {
    for (auto power : powers_) {
      if (n >= (power << 1)) {
        return false;
      }
      if (n >= power) {
        n -= power;
      }
    }
    return true;
  }
};
