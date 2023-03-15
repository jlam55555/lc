// General intuition: for each house, find the closest heater
// on the left and right. We don't need to do a binary search
// to find the closest heater if we traverse both the houses
// and the heaters in a sorted fashion.
//
// Thus, if M = number of houses, N = number of heaters:
// - Sort stage: O(M*log(M) + N*log(N)) time, O(1) space
// - Search stage: O(N+M) time (we traverse each house
//   and each heater exactly once), O(1) space
class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());
    int n(heaters.size());

    int res{}, prev_heater{-1}, next_heater{0};
    for (auto house : houses) {
      // Update prev_heater and next_heater.
      while (prev_heater < n - 1 && heaters[prev_heater + 1] <= house) {
        ++prev_heater;
      }
      while (next_heater < n && heaters[next_heater] < house) {
        ++next_heater;
      }

      // Note the invariant: distance_to_prev_heater and distance_to_next_heater
      // cannot both be INT_MAX, since there is at least one heater.
      auto distance_to_prev_heater{
          prev_heater == -1 ? INT_MAX : house - heaters[prev_heater]},
          distance_to_next_heater{
              next_heater == n ? INT_MAX : heaters[next_heater] - house};
      res = std::max(
          res, std::min(distance_to_prev_heater, distance_to_next_heater));
    }
    return res;
  }
};
