// Instinctively, this feels like a DP problem. We can
// probably record the minimum cost for each day from
// and fill this in in a bottom-up manner.
//
// min({
//    2 + minCostTickets(remaining days)
//    7 + minCostTickets(remaining days after 7)
//    15 + minCostTickets(remaining days after 30)
// })
//
// Each iterator `prev_day`, `prev_week`, and `prev_month`
// only iterates through the `days` array once, so this
// whole algorithm is O(n) time and O(n) space.
class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int n(days.size()), prev_day{-1}, prev_week{-1}, prev_month{-1};
    std::vector<int> days_cost;
    for (int i{}; i < n; ++i) {
      // Advance pointers.
      prev_day = i - 1;
      while (days[i] - days[prev_week + 1] >= 7) {
        ++prev_week;
      }
      while (days[i] - days[prev_month + 1] >= 30) {
        ++prev_month;
      }

      // Get the best result.
      days_cost.push_back(std::min({
          (prev_day < 0 ? 0 : days_cost[prev_day]) + costs[0],
          (prev_week < 0 ? 0 : days_cost[prev_week]) + costs[1],
          (prev_month < 0 ? 0 : days_cost[prev_month]) + costs[2],
      }));
    }
    return days_cost.back();
  }
};
