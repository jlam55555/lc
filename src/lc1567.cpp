class Solution {
public:
  int getMaxLen(vector<int> &nums) {

    int negStart = -1, posStart = -1, odds = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        odds = 0;
        negStart = posStart = -1;
        continue;
      }

      if (nums[i] < 0 && negStart < 0) {
        negStart = i;
      }
      if (nums[i] > 0 && posStart < 0) {
        posStart = i;
      }

      if (nums[i] < 0) {
        ++odds;
      }

      if (odds % 2 == 1) {
        maxLen = max(maxLen, i - negStart);
      } else if (odds % 2 == 0) {
        int tmp = INT_MAX;
        if (posStart >= 0) {
          tmp = posStart;
        }
        if (negStart >= 0) {
          tmp = min(negStart, tmp);
        }
        maxLen = max(maxLen, i - tmp + 1);
      }
    }

    return maxLen;
  }
};
