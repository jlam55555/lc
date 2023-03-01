// This is very similar to lc1736.cpp
class Solution {
public:
  static constexpr const int UNK{'?' - '0'};

  int countTime(string time) {
    int h1{time[0] - '0'}, h2{time[1] - '0'}, m1{time[3] - '0'},
        m2{time[4] - '0'};

    int possible_hours{1}, possible_minutes{1};
    if (h1 == UNK && h2 == UNK) {
      possible_hours = 24;
    } else if (h1 == UNK) {
      possible_hours = h2 < 4 ? 3 : 2;
    } else if (h2 == UNK) {
      possible_hours = h1 < 2 ? 10 : 4;
    }

    if (m1 == UNK && m2 == UNK) {
      possible_minutes = 60;
    } else if (m1 == UNK) {
      possible_minutes = 6;
    } else if (m2 == UNK) {
      possible_minutes = 10;
    }

    return possible_hours * possible_minutes;
  }
};
