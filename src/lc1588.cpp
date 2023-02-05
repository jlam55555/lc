// Algorithm:
// - For each letter, we keep track of the sums of the even and odd
//   subarrays ending at that letter.
// - For each letter, we create a new odd-length subarray (the
//   singleton subarray comprising the latest letter). All of the other
//   odd-length subarrays are the previous even-length subarrays plus
//   the new letter.
// - Similarly, for each letter, the even-length subarrays are
//   the old odd-length subarrays from the previous iteration plus
//   the new letter.
class Solution {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    int even_sum{}, even_count{}, odd_sum{}, odd_count{}, res{};
    for (int i : arr) {
      std::tie(even_sum, odd_sum, even_count, odd_count) = std::make_tuple(
          odd_sum + odd_count * i, even_sum + even_count * i + i, odd_count,
          even_count + 1);
      res += odd_sum;
    }
    return res;
  }
};
