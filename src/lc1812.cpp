class Solution {
public:
  bool squareIsWhite(string coordinates) {
    int r{coordinates[0] - '0'}, c{coordinates[1] - 'a'};
    return !((r ^ c) & 1);
  }
};
