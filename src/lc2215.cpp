class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    std::unordered_set<int> n1, n2;
    for (int n : nums1) {
      n1.insert(n);
    }
    for (int n : nums2) {
      n2.insert(n);
    }

    std::vector<int> diff1, diff2;
    for (auto i : n1) {
      if (!n2.count(i)) {
        diff1.push_back(i);
      }
    }
    for (auto i : n2) {
      if (!n1.count(i)) {
        diff2.push_back(i);
      }
    }
    return {diff1, diff2};
  }
};
