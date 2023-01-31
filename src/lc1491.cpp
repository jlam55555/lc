class Solution {
public:
  double average(vector<int> &salary) {
    int s_min = INT_MAX, s_max = INT_MIN;
    for (auto i : salary) {
      s_min = std::min(s_min, i);
      s_max = std::max(s_max, i);
    }

    int sum{};
    for (auto i : salary) {
      if (i != s_min && i != s_max) {
        sum += i;
      }
    }
    return ((double)sum) / (salary.size() - 2);
  }
};
