#define CLIP(a, l, r) std::max((l), std::min((a), (r)))

class Solution {
  using ull = unsigned long long;

public:
  // Can probably use a segment tree here, but I'm lazy.
  bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    ull bs{};
    int len(right - left + 1);

    for (const auto &range : ranges) {
      auto l{CLIP(range[0] - left, 0, len)},
          r{CLIP(range[1] + 1 - left, 0, len)};
      bs |= ((1llu << (r - l)) - 1) << l;
    }
    return !(bs ^ ((1llu << len) - 1));
  }
};
