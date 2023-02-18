class Solution {
public:
  // The idea is that we can easily generate F(i+1) based on F(i).
  // Each term's coefficient is increased by one, which means adding
  // each element of nums to F(i). However, there is one element
  // whose coefficient is set from n-1 to 0, so we have to subtract
  // this from F(i). Thus, the relationship is:
  //
  // F(i+1) = F(i) + sum(nums) - n*nums[n-1-i]
  //
  // I make heavy use of std::accumulate here but it is probably
  // more straightforward to do as a series of for loops. Just messing
  // around here.
  int maxRotateFunction(vector<int> &nums) {
    int sum{std::accumulate(nums.begin(), nums.end(), 0)},
        F_i{std::accumulate(nums.begin(), nums.end(), std::make_pair(0, 0),
                            [](const auto &acc, auto v) {
                              auto [i, sum] = acc;
                              return std::make_pair(i + 1, sum + i * v);
                            })
                .second},
        n(nums.size());

    return std::accumulate(nums.rbegin(), nums.rend(), std::make_pair(F_i, F_i),
                           [=](const auto &acc, auto v) {
                             auto [F_i, max] = acc;
                             F_i += sum - n * v;
                             return std::make_pair(F_i, std::max(F_i, max));
                           })
        .second;
  }
};
