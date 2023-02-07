class Solution {
public:
  int maximumPopulation(vector<vector<int>> &logs) {
    std::map<int, int> sorted_dates;
    for (const auto &log : logs) {
      ++sorted_dates[log[0]];
      --sorted_dates[log[1]];
    }

    int res{}, alive{}, most_alive{};
    for (const auto &[year, delta] : sorted_dates) {
      alive += delta;
      if (alive > most_alive) {
        res = year;
        most_alive = alive;
      }
    }
    return res;
  }
};
