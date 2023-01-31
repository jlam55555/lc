class Solution {
public:
  bool lemonadeChange(vector<int> &b) {
    int bills[2]{0};
    for (auto bill : b) {
      switch (bill) {
      case 5:
        ++bills[0];
        break;
      case 10:
        if (!bills[0]--) {
          return false;
        }
        ++bills[1];
        break;
      default:
        if (bills[1] && bills[0]) {
          --bills[1];
          --bills[0];
        } else if (bills[0] >= 3) {
          bills[0] -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
