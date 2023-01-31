class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    auto arr2 = arr;
    sort(arr.begin(), arr.end());

    long sum1 = 0, sum2 = 0;
    int chunks = 0;

    for (int i = 0; i < arr.size(); ++i) {
      sum1 += arr[i];
      sum2 += arr2[i];
      if (sum1 == sum2) {
        ++chunks;
      }
    }

    return chunks;
  }
};
