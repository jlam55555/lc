class Solution {
public:
  int waysToMakeFair(vector<int> &nums) {
    int n = nums.size();

    // cum sum from left and right
    // for both odds and evens
    // eww this code sucks
    int cs[2][n + 2];

    for (int i = 0; i <= n; ++i) {
      if (!i)
        cs[0][i] = 0;
      else if (i == 1)
        cs[0][i] = nums[0];
      else
        cs[0][i] = cs[0][i - 2] + nums[i - 1];
    }

    for (int i = n + 1; i >= 1; --i) {
      if (i == n + 1)
        cs[1][i] = 0;
      else if (i == n)
        cs[1][i] = nums[i - 1];
      else
        cs[1][i] = nums[i - 1] + cs[1][i + 2];
    }

    // for (int i = 0; i < n+2; ++i) {
    //     cout << cs[0][i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n+2; ++i) {
    //     cout << cs[1][i] << " ";
    // }
    // cout << endl;

    // check every split/removal
    int count = 0;
    for (int i = 0; i < n; ++i) {
      int evenCount = 0, oddCount = 0;

      // take two from left
      if (i > 1)
        evenCount += cs[0][i - 1];
      if (i)
        oddCount += cs[0][i];

      // take two from right
      if (i < n - 1)
        evenCount += cs[1][i + 2];
      if (i < n - 2)
        oddCount += cs[1][i + 3];

      // cout << i << " " << evenCount << " " << oddCount << endl;

      // check if sums of odds and evens are the same
      count += evenCount == oddCount;
    }

    return count;
  }
};
