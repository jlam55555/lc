class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    for (int i{}, j{}, n1(nums1.size()), n2(nums2.size()); i < n1 && j < n2;) {
      if (nums1[i] == nums2[j]) {
        return nums1[i];
      }
      while (i < n1 && nums1[i] < nums2[j]) {
        ++i;
      }
      while (j < n2 && nums2[j] < nums1[i]) {
        ++j;
      }
    }
    return -1;
  }
};
