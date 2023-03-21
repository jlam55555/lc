class Solution {
public:
  vector<int> findLonely(vector<int> &nums) {
    std::unordered_map<int, int> freqs;
    for (auto i : nums) {
      ++freqs[i];
    }
    std::vector<int> res;
    auto not_found{freqs.end()};
    for (auto [x, freq] : freqs) {
      if (freq == 1 && freqs.find(x - 1) == not_found &&
          freqs.find(x + 1) == not_found) {
        res.push_back(x);
      }
    }
    return res;
  }
};
