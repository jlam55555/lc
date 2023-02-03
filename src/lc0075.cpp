class Solution {
public:
  // Dutch flag problem. The solution is
  // in-place and one-pass. Visualization:
  //
  //   -->   -->                <--
  // |=====|=====|============|=====|
  //   RED  WHITE   unsorted    BLUE
  //   (0)   (1)                (2)
  // Initially, we will start at the left
  // and R,W=0, B=nums.end, and the whole
  // array is in the unsorted section.
  // When we encounter a value, we put it
  // in the correct spot.
  void sortColors(vector<int> &nums) {
    // Each of these point at the insertion index
    // of the next element of this color.
    int r{}, w{}, b{int(nums.size()) - 1};
    while (w <= b) {
      if (!nums[w]) {
        std::swap(nums[w++], nums[r++]);
      } else if (nums[w] == 1) {
        ++w;
      } else {
        std::swap(nums[w], nums[b--]);
      }
    }
  }
};
