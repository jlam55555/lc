class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    std::unordered_map<int, int> freqs;
    for (auto i : arr) {
      ++freqs[i];
    }

    std::unordered_set<int> vals;
    for (const auto &[unused, val] : freqs) {
      vals.insert(val);
    }

    return vals.size() == freqs.size();
  }
};
