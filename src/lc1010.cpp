class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    int counts[60] = {0}, count = 0;
    for (int i : time) {
      count += counts[(60 - i % 60) % 60];
      ++counts[i % 60];
    }
    return count;
  }
};
