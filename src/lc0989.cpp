class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    std::reverse(num.begin(), num.end());
    std::vector<int> res;
    auto i{0};
    auto carry{0};
    for (; i < num.size() || k || carry; ++i, k /= 10) {
      auto dig1{i < num.size() ? num[i] : 0};
      auto dig2{k % 10};
      auto half_sum{carry + dig1 + dig2};
      carry = half_sum / 10;
      res.push_back(half_sum % 10);
    }
    return std::vector<int>{res.rbegin(), res.rend()};
  }
};
