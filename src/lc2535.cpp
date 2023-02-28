class Solution {
public:
  int differenceOfSum(vector<int> &nums) {
    auto el_sum{std::accumulate(nums.begin(), nums.end(), 0)};
    auto dig_sum{
        std::accumulate(nums.begin(), nums.end(), 0, [](auto &acc, auto &v) {
          while (v) {
            acc += v % 10;
            v /= 10;
          }
          return acc;
        })};
    return std::abs(el_sum - dig_sum);
  }
};
