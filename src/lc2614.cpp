class Solution {
public:
  bool IsPrime(int n) {
    if (n == 1) {
      return false;
    }
    for (int i{2}, sqrtn(std::sqrt(n)); i <= sqrtn; ++i) {
      if (!(n % i)) {
        return false;
      }
    }
    return true;
  }

  int diagonalPrime(vector<vector<int>> &nums) {
    int n(nums.size()), res{};
    for (int i{}; i < n; ++i) {
      if (IsPrime(nums[i][i])) {
        res = std::max(res, nums[i][i]);
      }
      if (IsPrime(nums[i][n - 1 - i])) {
        res = std::max(res, nums[i][n - 1 - i]);
      }
    }
    return res;
  }
};
