/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
  if (numsSize == 0)
    return NULL;

  struct TreeNode *leftTree = sortedArrayToBST(nums, numsSize / 2),
                  *rightTree = sortedArrayToBST(nums + numsSize / 2 + 1,
                                                numsSize - numsSize / 2 - 1),
                  *retValue =
                      (struct TreeNode *)malloc(sizeof(struct TreeNode));

  *retValue = (struct TreeNode){
      .val = nums[numsSize / 2], .left = leftTree, .right = rightTree};
  return retValue;
}
