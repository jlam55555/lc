class Solution {
public:
  vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
    auto a_sum{0}, b_sum{0};
    std::unordered_set<int> as;
    for (auto i : aliceSizes) {
      a_sum += i;
      as.insert(i);
    }
    for (auto j : bobSizes) {
      b_sum += j;
    }

    // Need to find a pair [i, j]
    // such that i in aliceSizes
    // and j in bobSizes
    // and a_sum-i+j == b_sum-j+i

    // solve for i: i == (-b_sum+a_sum+2*j)/2
    for (auto j : bobSizes) {
      auto i{(-b_sum + a_sum + 2 * j) / 2};
      if (as.count(i)) {
        return {i, j};
      }
    }

    throw logic_error{"shouldn't happen"};
  }
};
