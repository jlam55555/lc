class Solution {
public:
  bool validMountainArray(vector<int> &arr) {
    // Find strictly increasing elements.
    auto i{0};
    for (; i < arr.size() - 1 && arr[i + 1] > arr[i]; ++i) {
    }

    if (i == 0 || i == arr.size() - 1) {
      return false;
    }

    // Find strictly decreasing elements.
    for (; i < arr.size() - 1 && arr[i + 1] < arr[i]; ++i) {
    }

    return i == arr.size() - 1;
  }
};
