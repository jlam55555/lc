/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
  int *res, *small, *large;

  small = numbers;
  large = numbers + numbersSize - 1;

  while (*small + *large != target)
    if (*small + *large < target)
      small++;
    else
      large--;

  res = (int *)malloc(2 * sizeof(int));
  res[0] = small - numbers + 1;
  res[1] = large - numbers + 1;
  *returnSize = 2;
  return res;
}
