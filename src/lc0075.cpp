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
    // `u` is the current unsorted index.
    int r{}, w{}, b{int(nums.size()) - 1}, u{};
    while (u <= b) {
      switch (nums[u]) {
      case 0:
        std::swap(nums[u++], nums[r++]);
        ++w;
        break;
      case 1:
        ++u;
        ++w;
        break;
      case 2:
        std::swap(nums[u], nums[b--]);
      }
    }
  }
};
