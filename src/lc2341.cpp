class Solution {
public:
  vector<int> numberOfPairs(vector<int> &nums) {
    int freqs[101]{};
    for (int i : nums) {
      ++freqs[i];
    }

    std::vector<int> res{0, 0};
    for (int i{}; i <= 100; ++i) {
      res[0] += freqs[i] / 2;
      res[1] += freqs[i] & 1;
    }
    return res;
  }
};
