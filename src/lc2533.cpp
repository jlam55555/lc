class Solution {
public:
  // I'm kind of lazy.
  vector<int> separateDigits(vector<int> &nums) {
    std::string s;
    for (auto num : nums) {
      s += std::to_string(num);
    }
    std::vector<int> res;
    for (auto c : s) {
      res.push_back(c - '0');
    }
    return res;
  }
};
