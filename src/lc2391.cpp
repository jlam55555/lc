// Keep track of the units of garbage and the traveling
// distances separately for convenience. The end result
// is the sum of (distance traveled) and (units of garbage
// collected).
class Solution {
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    int travel_times[3]{}, travel_time{}, total_units{};
    for (int i{}, n(garbage.size()); i < n;
         total_units += garbage[i].length(),
         travel_time += i < n - 1 ? travel[i] : 0, ++i) {
      for (auto c : garbage[i]) {
        switch (c) {
        case 'M':
          travel_times[0] = travel_time;
          break;
        case 'P':
          travel_times[1] = travel_time;
          break;
        default:
          travel_times[2] = travel_time;
          break;
        }
      }
    }
    return travel_times[0] + travel_times[1] + travel_times[2] + total_units;
  }
};
