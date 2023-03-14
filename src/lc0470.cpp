// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// Rejection sampling approach given by the editorial.
// We can generate a uniform range of 49 numbers using
// two calls to rand7(). From this we can sample the
// uniform range [1, 40], and retry if we get a number
// in [41, 49].
class Solution {
public:
  int rand10() {
    int x;
    do {
      x = 7 * (rand7() - 1) + rand7();
    } while (x > 40);
    return x % 10 + 1;
  }
};
