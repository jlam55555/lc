class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                            vector<int> &nums3) {
    unordered_map<int, int> nums{};

    for (auto i : nums1) {
      nums[i] |= 0b1;
    }
    for (auto i : nums2) {
      nums[i] |= 0b10;
    }
    for (auto i : nums3) {
      nums[i] |= 0b100;
    }

    int i;
    vector<int> res{};
    for (const auto &p : nums) {
      i = p.second;
      if ((i & 0b110) == 0b110 || (i & 0b101) == 0b101 ||
          (i & 0b011) == 0b011) {
        res.push_back(p.first);
      }
    }

    return res;
  }
};
