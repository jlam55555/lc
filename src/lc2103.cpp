class Solution {
public:
  int countPoints(string rings) {
    int rods[10]{};
    int colors[26]{0, 0x1, 0, 0, 0, 0, 0x2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x4};
    for (int i{}, n(rings.size()); i < n; i += 2) {
      rods[rings[i + 1] - '0'] |= colors[rings[i] - 'A'];
    }
    int res{};
    for (int i{}; i < 10; ++i) {
      res += rods[i] == 0x7;
    }
    return res;
  }
};
