class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {

    vector<vector<long>> is{};

    for (int i = 0; i < nums.size(); ++i) {
      is.push_back({nums[i], i});
    }

    sort(is.begin(), is.end());

    // try to find the next largest and next smallest element for each element
    for (int i = 0; i < nums.size(); ++i) {
      int curval = is[i][0];
      int curind = is[i][1];

      // cout << "cur: " << curval << endl;

      // try to find an element smaller
      for (int j = i - 1; j >= 0 && abs(curval - is[j][0]) <= t; --j) {
        // cout << is[j][0] << " " << abs(curind-is[j][1]) << endl;
        if (abs(curind - is[j][1]) <= k) {
          return true;
        }
      }

      // try to find an element larger
      for (int j = i + 1; j < nums.size() && abs(curval - is[j][0]) <= t; ++j) {
        // cout << is[j][0] << " " << abs(curind-is[j][1]) << endl;
        if (abs(curind - is[j][1]) <= k) {
          return true;
        }
      }
    }

    return false;
  }
};
