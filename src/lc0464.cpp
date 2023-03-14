#define CAN_FORCE_WIN 1
#define CANNOT_FORCE_WIN 2

// Brute force with memoization.
class Solution {
  // Using this rather than a hashmap made the largest change
  // in performance. Inspired by @zzg_zzm's solution.
  uint8_t dp_[1u << 20]{};

public:
  // Returns true if the specified player can win.
  uint8_t canIWin(int k, int n, unsigned remaining) {
    // Memoization.
    if (dp_[remaining]) {
      return dp_[remaining];
    }

    // This player guarantees a win if the next player cannot
    // guarantee a win.
    for (unsigned i{1}, mask{1}; i <= k; ++i, mask <<= 1) {
      if (!(mask & remaining)) {
        continue;
      }
      // First condition allows us to reduce one layer of depth.
      if (n <= i || canIWin(k, n - i, remaining & ~mask) == CANNOT_FORCE_WIN) {
        return dp_[remaining] = CAN_FORCE_WIN;
      }
    }
    return dp_[remaining] = CANNOT_FORCE_WIN;
  }

  bool canIWin(int k, int n) {
    // Impossible for either to win.
    if (n > k * (k + 1) / 2) {
      return false;
    }

    // Brute force.
    return canIWin(k, n, (1u << k) - 1) == CAN_FORCE_WIN;
  }
};
