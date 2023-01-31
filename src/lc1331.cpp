class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    std::map<int, int> ranks;
    for (auto i : arr) {
      ranks[i] = 0;
    }

    auto r{0};
    for (auto &[unused, rank] : ranks) {
      rank = ++r;
    }

    for (auto &i : arr) {
      i = ranks[i];
    }

    return arr;
  }
};
