// Basically a Knapsack 0-1 problem. The answer
// will be the minimal difference between the subset
// sums of a binary partition of the stones.
//
// I'll give a little explanation below because I wasn't
// too satisfied with @lee215's explanation in his solution:
//
// To explain why this is a knapsack problem, we can
// express the problem as so: initially we have n stones
// {a_1, a_2, ... , a_n}.
//
// After a collision, we "combine" two stones a_i and a_j
// into a single stone of weight (a_i - a_j). We keep
// doing this until we have a single element left. This
// element a_k must also be of the form a_l - a_k, and
// the same is true of a_l and a_k until we reach elements
// from the original set {a_1, ... , a_n}.
//
// In other words, a_k for the case of k=5 might look
// something like (1):
//
// (1) a_k = (a_4 - (a_2 - (a_1 - a_3))) - a_5
//
// The order of operations denotes the order of collisions.
// Note that we can rewrite this as a partition of {a}
// into positive and negative terms:
//
// (2) a_k = (a_4 + a_1) - (a_2 + a_3 + a_5)
//
// The goal then is to find the minimum value of a_k (>= 0),
// which is to say that we want to find the minimal difference
// between a partition of the stones. This is simply the 0-1
// knapsack problem.
//
// Going backwards, we know that we can find the minimum
// a_k >= 0 (solving equation (2)). It is fairly trivial to
// rewrite (2) in the form of (1), i.e., to interpret the
// partition of stones into some collision sequence. Note that
// there is no unique equation of the form (1) corresponding
// to the equation (2), and also note that each subexpression
// should also be nonnegative so we don't have stones with
// negative weight; this is easy to do as we can simply reverse
// the order of subtraction.
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    // 0-1 knapsack. See lc0416.cpp for another example.
    //
    // I empirically see slightly better results on LC if I
    // align to a cache-line size (64 bytes) rather than
    // making the bitset size exactly 1501 bits, although
    // I don't know if this is my imagination.
    std::bitset<2048> dp{1};
    for (auto stone : stones) {
      dp |= dp << stone;
    }

    // Find the greatest subset sum <= half
    // the total sum.
    auto total{std::accumulate(stones.begin(), stones.end(), 0)};
    for (int i{total / 2};; --i) {
      if (dp.test(i)) {
        return std::abs(i - (total - i));
      }
    }

    throw logic_error{"shouldn't happen"};
  }
};
