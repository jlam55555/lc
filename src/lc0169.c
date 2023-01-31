int majorityElement(int *nums, int numsSize) {

  int cand, count, i;

  for (i = 1, cand = nums[0], count = 1; i < numsSize; i++) {
    if (!count)
      cand = nums[i];
    if (nums[i] == cand)
      count++;
    else
      count--;
  }

  return cand;
}
