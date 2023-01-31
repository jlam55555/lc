class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int max_product = nums[0], cur_prod_max = max_product,
        cur_prod_min = max_product;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        swap(cur_prod_max, cur_prod_min);
      }

      cur_prod_max = max(nums[i], nums[i] * cur_prod_max);
      cur_prod_min = min(nums[i], nums[i] * cur_prod_min);

      max_product = max(max_product, cur_prod_max);
    }

    return max_product;
  }
};
