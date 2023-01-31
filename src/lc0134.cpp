class Solution {
public:
  // This was a lot simpler than I thought it would be.
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size(), net{0};
    int gas_min = INT_MAX, gas_min_i = 0;
    for (int i{}; i < n; ++i) {
      net += gas[i] - cost[i];

      if (net < gas_min) {
        gas_min = net;
        gas_min_i = i;
      }
    }

    // Short circuit.
    if (net < 0) {
      return -1;
    }

    return (gas_min_i + 1) % n;
  }
};
