class Solution {
public:
  // Return the number of elements that are not the smallest
  // or greatest elements.
  int countElements(vector<int> &nums) {
    int smallest{INT_MAX}, smallest_count{}, largest{INT_MIN}, largest_count{};
    for (int i : nums) {
      if (i < smallest) {
        smallest = i;
        smallest_count = 1;
      } else if (i == smallest) {
        ++smallest_count;
      }
      if (i > largest) {
        largest = i;
        largest_count = 1;
      } else if (i == largest) {
        ++largest_count;
      }
    }
    if (largest == smallest) {
      return 0;
    }
    return nums.size() - smallest_count - largest_count;
  }
};
