class Solution {
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr) {
    std::unordered_map<int, int> freqs;
    for (auto i : target) {
      ++freqs[i];
    }
    for (auto i : arr) {
      if (!freqs[i]) {
        return false;
      } else if (!--freqs[i]) {
        freqs.erase(i);
      }
    }
    return freqs.empty();
  }
};
