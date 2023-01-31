class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    std::unordered_set<int> s1{nums1.begin(), nums1.end()},
        s2{nums2.begin(), nums2.end()};
    std::vector<int> res{};
    for (auto i : s2) {
      if (s1.count(i)) {
        res.push_back(i);
      }
    }
    return res;
  }
};
