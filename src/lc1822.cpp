class Solution {
public:
  int arraySign(vector<int> &nums) {
    bool sign{};
    for (int i : nums) {
      if (!i) {
        return 0;
      }
      sign ^= i < 0;
    }
    return sign ? -1 : 1;
  }
};
