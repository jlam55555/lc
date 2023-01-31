class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &arr) {
    int all_sum = 0;
    for (auto val : arr) {
      all_sum += val;
    }

    if (all_sum % 3 != 0) {
      return false;
    }
    all_sum /= 3;

    // get three groups of numbers that sum to all_sum/3
    int groups = 0, cur_sum = 0;
    for (auto val : arr) {
      if ((cur_sum += val) == all_sum) {
        ++groups;
        cur_sum = 0;
      }
    }

    // >= b/c of possible all 0's
    return groups >= 3;
  }
};
