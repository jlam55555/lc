class Solution {
public:
  // Run a simulation.
  int minNumberOfHours(int initialEnergy, int initialExperience,
                       vector<int> &energy, vector<int> &experience) {
    int en{initialEnergy}, ex{initialExperience}, n(energy.size()), res{};
    for (int i{}; i < n; ++i) {
      if (en <= energy[i]) {
        res += energy[i] - en + 1;
        en = energy[i] + 1;
      }
      if (ex <= experience[i]) {
        res += experience[i] - ex + 1;
        ex = experience[i] + 1;
      }
      en -= energy[i];
      ex += experience[i];
    }
    return res;
  }
};
