class Solution {
public:
  int averageValue(vector<int> &nums) {
    int sum{}, count{};
    for (int i : nums) {
      if (!(i & 1) && !(i % 3)) {
        ++count;
        sum += i;
      }
    }
    return count ? sum / count : 0;
  }
};
