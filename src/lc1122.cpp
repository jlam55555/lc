class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    std::map<int, int> freqs1;
    for (const auto i : arr1) {
      ++freqs1[i];
    }

    std::vector<int> res;
    for (const auto j : arr2) {
      for (auto i{0}; i < freqs1[j]; ++i) {
        res.push_back(j);
      }
      freqs1.erase(j);
    }

    for (const auto &[j, freq] : freqs1) {
      for (auto i{0}; i < freq; ++i) {
        res.push_back(j);
      }
    }

    return res;
  }
};
