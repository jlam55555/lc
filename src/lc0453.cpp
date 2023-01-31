class Solution {
public:
  int minMoves(vector<int> &nums) {

    // find min
    int minElem = INT_MAX;
    long long sum = 0;
    for (int i : nums) {
      sum += i;
      minElem = min(minElem, i);
    }

    sum -= minElem * nums.size();

    return sum;
  }
};
