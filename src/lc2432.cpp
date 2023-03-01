class Solution {
public:
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int start_ts{}, longest{}, longest_id{INT_MAX};
    for (const auto &log : logs) {
      auto id{log[0]}, end_ts{log[1]}, elapsed{end_ts - start_ts};
      if (elapsed > longest || (elapsed == longest && id < longest_id)) {
        longest = elapsed;
        longest_id = id;
      }
      start_ts = end_ts;
    }
    return longest_id;
  }
};
