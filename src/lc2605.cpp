class Solution {
public:
  int minNumber(vector<int> &nums1, vector<int> &nums2) {
    int freqs1[10]{}, freqs2[10]{}, nums1_min{9}, nums2_min{9};
    for (int i : nums1) {
      ++freqs1[i];
      nums1_min = std::min(nums1_min, i);
    }
    for (int i : nums2) {
      ++freqs2[i];
      nums2_min = std::min(nums2_min, i);
    }

    // Single digit match.
    for (int i{1}; i < 10; ++i) {
      if (freqs1[i] && freqs2[i]) {
        return i;
      }
    }

    // No single digit match.
    return nums1_min < nums2_min ? nums1_min * 10 + nums2_min
                                 : nums2_min * 10 + nums1_min;
  }
};
