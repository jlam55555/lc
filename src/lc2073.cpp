class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    // get count at k
    int count = tickets[k];

    int res = count, i;

    for (i = 0; i < k; ++i) {
      res += min(count, tickets[i]);
    }

    for (i = k + 1; i < tickets.size(); ++i) {
      res += min(count - 1, tickets[i]);
    }

    return res;
  }
};
