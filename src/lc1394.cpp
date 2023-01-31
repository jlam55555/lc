class Solution {
public:
  int findLucky(vector<int> &arr) {
    std::map<int, int> freq;
    for (auto i : arr) {
      ++freq[i];
    }

    for (auto i{freq.rbegin()}, end{freq.rend()}; i != end; ++i) {
      if (auto [a, b] = *i; a == b) {
        return a;
      }
    }
    return -1;
  }
};
