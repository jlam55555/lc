class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    auto min_gt{INT_MAX};
    for (auto c : letters) {
      if (c > target && c < min_gt) {
        min_gt = c;
      }
    }
    return min_gt == INT_MAX ? letters.front() : min_gt;
  }
};
