class Solution {
public:
  struct mySort {
    // sort by vector end
    bool operator()(const vector<int> &i1, const vector<int> &i2) {
      return i1[1] < i2[1];
    }
  };

  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // do this greedily, sort by the end time
    sort(intervals.begin(), intervals.end(), mySort{});

    int removeCount = 0;
    auto currentInterval = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      // overlap condition
      if (intervals[i][0] < intervals[currentInterval][1]) {
        ++removeCount;
      }
      // not overlapping, set next interval
      else {
        currentInterval = i;
      }
    }

    return removeCount;
  }
};
