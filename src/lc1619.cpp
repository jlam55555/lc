class Solution {
public:
  double trimMean(vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    int N(arr.size()), edge(0.05 * N), sum{};
    for (int i{edge}; i < N - edge; ++i) {
      sum += arr[i];
    }
    return sum / (0.9 * N);
  }
};
