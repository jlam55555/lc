class Solution {
public:
  long long sumTo(long long n) { return n * (n + 1) / 2; }

  int maxProfit(vector<int> &inventory, int orders) {
    std::sort(inventory.begin(), inventory.end());
    long long len = inventory.size(), diff;
    long long res = 0;
    long long count = 1;

    for (long long i = len - 1,
                   diff = inventory[i] - (i ? inventory[i - 1] : 0);
         i >= 0;
         i--, diff = i < 0 ? 0 : inventory[i] - (i ? inventory[i - 1] : 0)) {

      // cout << "diff " << diff << endl;

      if (diff * count < orders) {
        res += count * (sumTo(inventory[i]) - sumTo(inventory[i] - diff));
        orders -= diff * count;
      } else {
        long long layers = orders / count;

        res += count * (sumTo(inventory[i]) - sumTo(inventory[i] - layers));

        orders -= layers * count;
        // cout << "layers " << layers << " res " << res << " remaining orders "
        // << orders << endl;
        res += (inventory[i] - layers) * orders;
        return res % 1000000007;
      }

      // cout << res << " " << orders << endl;
      count++;
    }

    return -1;
  }
};
