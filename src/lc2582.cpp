// Look at the number modulo n-1. For example (n=4):
// 1 2 3
// 4 3 2
// 1 2 3
// 4 3 2
// ...
class Solution {
public:
  int passThePillow(int n, int time) {
    bool ascending{time / (n - 1) % 2 == 0};
    int i{time % (n - 1)};

    return ascending ? i + 1 : n - i;
  }
};
