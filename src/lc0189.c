// couldn't get this exactly right by myself, required some peeking
void rotate(int *nums, int numsSize, int k) {

  if (!(k %= numsSize))
    return;

  int i, count, tmp, pos, prev;

  for (i = 0, count = 0; count < numsSize; i++) {

    pos = i;
    prev = nums[i];
    do {
      tmp = nums[(pos + k) % numsSize];
      nums[(pos + k) % numsSize] = prev;
      prev = tmp;
      count++;
      pos = (pos + k) % numsSize;
    } while (pos != i);
  }
}
