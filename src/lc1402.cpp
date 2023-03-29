// Definitely want all the non-negative dishes,
// then it's just a matter of how many negative
// dishes we want to include.
//
// We can quickly iterate through the search space
// by realizing that we can easily get from one
// like-time-coefficient-candidate to the next by adding
// one negative number plus the (unweighted) sum of
// all numbers in the weighted sum so far. I.e., we are
// increasing the coefficient of each number in the weighted
// sum by one. This solution is very similar to a different
// question I've seen on Leetcode (probably a medium question),
// but I can't find it at the moment.
//
// As an illustration, looking at the first example:
// -1, -8, 0, 5, -9
//
// Sort:
// -9, -8, -1, 0, 5
//
// Weighted sum of nonnegative numbers:
// 0*1 + 5*2 == 10
//
// Try adding negative numbers:
// -1*1 + 0*2 + 5*2 == -1 + 10 + (0 + 5) == 15
// -8*1 + -1*2 + 0*3 + 5*4 == -8 + 15 + (-1 + 0 + 5) == 11
// -9*1 + -8*2 + -1*3 + 0*4 + 5*5 == -9 + 11 + (-8 + -1 + 0 + 5) == -1
//
// Clearly, the best weighted sum is 15.
class Solution {
public:
  int maxSatisfaction(vector<int> &satisfaction) {
    // Get numbers in sorted order.
    std::sort(satisfaction.begin(), satisfaction.end());

    // Find position of first nonnegative element.
    int pos_i(std::distance(
        satisfaction.begin(),
        std::lower_bound(satisfaction.begin(), satisfaction.end(), 0)));

    // Keep track of all numbers we've seen so far (weighted and unweighted).
    int w_sum{}, uw_sum{};
    for (int n(satisfaction.size()), i{pos_i}; i < n; ++i) {
      w_sum += satisfaction[i] * (i - pos_i + 1);
      uw_sum += satisfaction[i];
    }

    // Try adding negative numbers.
    int res{w_sum};
    for (int i{pos_i - 1}; i >= 0; --i) {
      res = std::max(res, w_sum += (uw_sum += satisfaction[i]));
    }

    return res;
  }
};
