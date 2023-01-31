class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    int max_dur = releaseTimes[0], max_i = 0;
    for (int i = 1; i < releaseTimes.size(); ++i) {
      if (releaseTimes[i] - releaseTimes[i - 1] > max_dur ||
          (releaseTimes[i] - releaseTimes[i - 1] == max_dur &&
           keysPressed[i] > keysPressed[max_i])) {
        max_dur = releaseTimes[i] - releaseTimes[i - 1];
        max_i = i;
      }
    }
    return keysPressed[max_i];
  }
};
