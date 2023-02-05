// This question is very similar to computing
// the h-index (lc0274.cpp).
class Solution {
public:
  int specialArray(vector<int> &citations) {
    std::sort(citations.begin(), citations.end());

    for (auto i{0}; i < citations.size(); ++i) {
      auto paper_count{citations.size() - i};
      if (citations[i] >= paper_count &&
          (!i || citations[i - 1] < paper_count)) {
        return paper_count;
      }
    }

    return -1;
  }
};
