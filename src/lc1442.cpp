// Idea: if two contiguous subarrays have an equal XOR
// value, then when you XOR their results together,
// you'll get zero. The cool thing is that no matter how
// you split the subarray into two non-empty subarrays
// (assuming it has length > 2) you will get two subarrays
// with equal XORs.
//
// This problem thus becomes a counting problem.
class Solution {
public:
  int countTriplets(vector<int> &arr) {
    std::unordered_map<int, std::vector<int>> xors;
    xors[0].push_back(-1);
    int xor_{};
    for (int i{}, n(arr.size()); i < n; ++i) {
      xors[xor_ ^= arr[i]].push_back(i);
    }

    int res{};
    for (auto [unused, is] : xors) {
      for (int i1{}, len(is.size()); i1 < len; ++i1) {
        for (int i2{i1 + 1}; i2 < len; ++i2) {
          res += is[i2] - is[i1] - 1;
        }
      }
    }
    return res;
  }
};
