class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    // only possible that two elements have this property
    int n = nums.size(), target = n / 3 + 1;

    unordered_map<int, int> hist{};
    vector<int> res{};

    for (auto i : nums) {
      if (++hist[i] == target) {
        res.push_back(i);
      }
    }

    return res;
  }
};
