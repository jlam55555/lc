class Solution {
public:
  int hIndex(vector<int> &citations) {
    int l{}, r(citations.size());

    // Round down makes this a little messier.
    while (l < r) {
      auto m{(l + r + 1) >> 1};
      if (citations[citations.size() - m] >= m) {
        l = m;
      } else {
        r = m - 1;
      }
    }

    return l;
  }
};
