typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  struct vsort {
    // sort by end of array
    bool operator()(const vi &v1, const vi &v2) { return v1[1] < v2[1]; }
  };

  // based on https://stackoverflow.com/a/69222752
  int lower_bound(map<int, int> &m, int val) {
    // if (val == 3) {
    //     cout << " " << m.count(val) << " " << m[val] << " " <<
    //     m.upper_bound(val)->second
    // }

    // if (m.count(val)) return m[val];
    auto upper_node = m.upper_bound(val);
    if (upper_node != m.begin())
      upper_node--;

    // cout << "found " << val << " " << upper_node->first << " " <<
    // upper_node->second << endl;

    return upper_node->second;
  }

  int maxTwoEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end(), vsort{});

    map<int, int> dp{};
    dp[INT_MIN] = 0;

    int prev_best, cur_best, max_score = INT_MIN;

    for (vi ev : events) {
      prev_best = lower_bound(dp, ev[0] - 1);
      max_score = max(max_score, prev_best + ev[2]);

      prev_best = lower_bound(dp, ev[1]);
      cur_best = dp[ev[1]] = max(prev_best, ev[2]);

      // cout << ev[0] << " " << ev[1] << " " << ev[2] << " " << cur_best << " "
      // << max_score << endl;
    }

    return max_score;
  }
};
