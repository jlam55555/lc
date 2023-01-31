class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int one{}, two{};
    for (auto i : nums) {
      // K-map time! Basically need a three-cycle.
      std::tie(one, two) =
          std::make_pair((i & ~one & ~two) | (~i & one & two),
                         ~(~i & ~one & ~two) & ~(i & ~one & two));
    }
    return two;
  }
};
