class Solution {
public:
  // I think this has a growth ratio similar to Fibonacci
  // so the runtime shouldn't be too high.
  // Digits 1-9 have 1 digit each, total = 9 digits
  // Digits 10-99 have 2 digits each, total = 180 digits
  // Digits 100-999 have 3 digits each, total = 2700 digits
  // ...
  //
  // We can use this to find out how many digits the number has.
  // Then we can divide by the number of digits to find the
  // index, and look up the digit within that number. I think
  // this is fairly straightforward, but the counting can
  // get a bit tricky.
  int findNthDigit(int n) {
    // Make n 0-indexed;
    --n;

    // Find out how many digits comprise the number that
    // the nth digit lies in.
    long num_digits{}, digit_count{};
    for (; n >= digit_count;
         n -= digit_count, ++num_digits,
         digit_count = 9 * long(std::pow(10, num_digits - 1)) * num_digits)
      ;

    // Find the index of the number that the nth digit lies in.
    // That number is i, and we're looking at the jth digit
    // in k.
    long i{n / num_digits + long(std::pow(10, num_digits - 1))},
        j{n % num_digits};
    return int(i / std::pow(10, num_digits - j - 1)) % 10;
  }
};
