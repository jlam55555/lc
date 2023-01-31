class Solution {
public:
  bool judgeCircle(string moves) {
    auto i{0}, j{0};

    for (auto move : moves) {
      switch (move) {
      case 'R':
        ++j;
        break;
      case 'L':
        --j;
        break;
      case 'U':
        --i;
        break;
      default:
        ++i;
      }
    }

    return !(j || i);
  }
};
