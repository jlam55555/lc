class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int timeSum, i;

    if (timeSeries.empty())
      return 0;

    for (i = 1, timeSum = 0; i < timeSeries.size(); ++i)
      timeSum += ::min(timeSeries[i] - timeSeries[i - 1], duration);

    return timeSum + duration;
  }
};
