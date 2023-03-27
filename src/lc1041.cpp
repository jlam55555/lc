// Bounded if it returns to the center or if it ends up in
// a different orientation (so it will either end up back
// at the center in 2 or 4 turns).
class Solution {
public:
  bool isRobotBounded(string instructions) {
    int i{}, j{}, dir{};
    for (char c : instructions) {
      switch (c) {
      case 'G':
        switch (dir) {
        case 0:
          --i;
          break;
        case 1:
          ++j;
          break;
        case 2:
          ++i;
          break;
        case 3:
          --j;
          break;
        }
        break;
      case 'L':
        dir = (dir + 3) % 4;
        break;
      case 'R':
        dir = (dir + 1) % 4;
      }
    }
    return (!i && !j) || dir;
  }
};
