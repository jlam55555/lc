class Solution {
public:
  int hIndex(vector<int> &citations) {
    std::sort(citations.begin(), citations.end());

    for (auto i{0}; i < citations.size(); ++i) {
      auto paper_count{citations.size() - i};
      if (citations[i] >= paper_count) {
        return paper_count;
      }
    }

    return 0;
  }
};
