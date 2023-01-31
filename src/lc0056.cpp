class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    vector<int> interval = intervals[0];
    vector<vector<int>> res{};

    for (int i = 1; i < intervals.size(); i++) {

      // create new interval
      if (intervals[i][0] > interval[1]) {
        res.push_back(interval);
        interval = intervals[i];
      }
      // append to existing interval
      else {
        interval[1] = max(interval[1], intervals[i][1]);
      }
    }
    res.push_back(interval);

    return res;
  }
};
