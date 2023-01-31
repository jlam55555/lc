class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    if (nums.size() == 1)
      return 0;

    int largest, secondLargest, largestIndex;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > largest) {
        secondLargest = largest;
        largest = nums[i];
        largestIndex = i;
      } else if (nums[i] > secondLargest) {
        secondLargest = nums[i];
      }
    }

    return largest >= secondLargest << 1 ? largestIndex : -1;
  }
};
