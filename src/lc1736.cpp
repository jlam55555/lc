// This is very similar to lc2437.cpp
class Solution {
public:
  string maximumTime(string time) {
    // Handle hours.
    if (time[0] == '?' && time[1] == '?') {
      time[0] = '2';
      time[1] = '3';
    } else if (time[0] == '?') {
      time[0] = time[1] < '4' ? '2' : '1';
    } else if (time[1] == '?') {
      time[1] = time[0] == '2' ? '3' : '9';
    }

    // Handle minutes.
    if (time[3] == '?') {
      time[3] = '5';
    }
    if (time[4] == '?') {
      time[4] = '9';
    }
    return time;
  }
};
