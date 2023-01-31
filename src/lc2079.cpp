class Solution {
public:
  int wateringPlants(vector<int> &plants, int capacity) {
    int totalTime = 0;

    // watering can at position -1
    for (int i = 0; i < plants.size();) {
      // for (int j = 0; j < plants.size(); ++j) {
      //     cout << plants[j] << " ";
      // }
      // cout << endl;

      // count water to get to first nonempty position
      int time = i + 1;
      int start = i;
      int bucket = capacity;

      // cout << "time1: " << time << endl;

      // keep moving until bucket is empty or end is reached
      while (i < plants.size() && bucket >= plants[i]) {
        // cout << "bucket before " << i << ": " << bucket << endl;
        bucket -= plants[i];
        plants[i] = 0;
        // cout << "bucket before " << i << ": " << bucket << endl;
        i++;
      }
      time += (i - 1) - start;

      // cout << "time2: " << time << " i: " << i << endl;

      // calculate return trip cost (if not at end)
      if (i != plants.size()) {
        time += i;
      }
      totalTime += time;

      // cout << "time3: " << time << endl;

      // break;
    }
    return totalTime;
  }
};
