class Solution {

  struct mySort {
    // sort by ending index
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
      return p1.first < p2.first;
    }
  };

public:
  vector<int> partitionLabels(string s) {

    // need to get the last, greatest for each character
    // and then merge intervals

    vector<pair<int, int>> hist =
        vector<pair<int, int>>(26, {INT_MAX, INT_MIN});

    // get min, max for each one
    for (int i = 0; i < s.length(); ++i) {
      hist[s[i] - 'a'].first = min(hist[s[i] - 'a'].first, i);
      hist[s[i] - 'a'].second = i;
    }

    // remove letters that are not there
    int i, j;
    for (i = j = 0; i < hist.size(); ++i) {
      if (hist[i].first < INT_MAX) {
        hist[j++] = hist[i];
      }
    }
    hist.resize(j);

    sort(hist.begin(), hist.end(), mySort{});

    // merge overlapping intervals
    pair<int, int> interval = hist[0];
    vector<int> res{};

    for (int i = 1; i < hist.size(); ++i) {
      // overlap
      if (hist[i].first < interval.second) {
        interval.second = max(interval.second, hist[i].second);
      }
      // no overlap, create a new interval
      else {
        res.push_back(interval.second - interval.first + 1);
        interval = hist[i];
      }
    }
    res.push_back(interval.second - interval.first + 1);

    return res;
  }
};
