class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    std::unordered_map<int, int> nums1_hist{};
    for (auto i : nums1) {
      ++nums1_hist[i];
    }
    std::vector<int> res{};
    for (auto i : nums2) {
      if (nums1_hist[i]-- > 0) {
        res.push_back(i);
      }
    }
    return res;
  }
};
