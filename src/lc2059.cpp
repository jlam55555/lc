class Solution {
public:
  int minimumOperations(vector<int> &nums, int start, int goal) {
    // count number of steps to get to each position
    vector<int> dp(1001, INT_MAX);

    queue<pair<int, int>> q{};
    q.push({start, 0});

    // cout << "beginning: " << start << " " << goal << endl;

    while (!q.empty()) {
      auto qtop = q.front();
      q.pop();

      int v = qtop.first, dist = qtop.second;

      // cout << "next: " << v << " " << dist << endl;

      if (v == goal) {
        return dist;
      }

      if (v < 0 || v > 1000 || dp[v] != INT_MAX) {
        // number already explored or invalid
        continue;
      }

      for (auto n : nums) {
        // cout << "  pushing: " << (v+n) << " " << (v^n) << " " << (v-n) <<
        // endl;
        q.push({v + n, dist + 1});
        q.push({v ^ n, dist + 1});
        q.push({v - n, dist + 1});
      }

      dp[v] = dist;
    }

    return -1;
  }
};

// [1,3]
// 6
// 4

// 6+1 -> 7
// 6-1 -> 5
// 6-2 ->
