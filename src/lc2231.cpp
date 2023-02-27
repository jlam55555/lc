class Solution {
public:
  // Sort odd and even digits.
  // Maybe we can do this in place but I'm lazy.
  int largestInteger(int num) {
    std::vector<int> odd, even;
    int num_copy{num};
    while (num) {
      auto digit{num % 10};
      ((digit & 1) ? odd : even).push_back(digit);
      num /= 10;
    }

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());

    for (long j{}, k{}, multiplier{1}; num_copy;
         num_copy /= 10, multiplier *= 10) {
      if ((num_copy % 10) & 1) {
        num += odd[j++] * multiplier;
      } else {
        num += even[k++] * multiplier;
      }
    }
    return num;
  }
};
