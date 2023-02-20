// This is an O(n*log(n)) time, O(log(n)) time solution that
// is a very literal translation of how I would do this
// problem. This is a divide-and-conquer solution that goes
// from the largest to the smallest bit. The general intuition
// lies around the fact that if we have a set of numbers such
// as:
//
// 0b00xx
// 0b00xx
// 0b00xx
// 0b01xx
// 0b01xx
// 0b01xx
//
// Then we know the answer will be the XOR of one number from
// the first four numbers (prefix 0b00xx) and one number from
// the remaining three numbers (prefix 0b01xx). So we divide
// the set into two candidate groups. We then continue as thus:
//
// 0b000x + GROUP 1 + SUBGROUP 1 (next bit=0)
// 0b000x |         |
// 0b001x |         + SUBGROUP 2 (next bit=1)
// 0b001x |         |
//
// 0b010x + GROUP 2 + SUBGROUP 3 (next bit=0)
// 0b011x |         + SUBGROUP 4 (next bit=1)
//
// Looking at the next bit, we see that the answer is either
// going to be:
// - Something with prefix 0b00x ^ 0b11x; or
// - Something with prefix 0b01x ^ 0b10x
// Taking the "diagonals" of the four subgroups. This continues
// until we have a subgroup of size one, in which we take the
// max of all of the XORs between that subgroup and the diagonal
// subgroup. Note that there may also be cases when there are
// no diagonal subgroups (i.e., there are only non-empty subgroups
// 1 and 3, or 2 and 4) -- in this case, we simply proceed forwards
// to the next bit.
//
// This seems to be pretty fast, at least by LC standards;
// it beats >99% solutions in space and time.
//
// The top solution by @tangx668 is pretty clever. It takes
// the same approach of going bit-by-bit (from MSB to LSB)
// to determine the next bit of the result. However, at each
// stage a clever use of a prefix mask is used to narrow down
// the list of candidates at each stage. This uses a
// 2-sum-like trick as pointed out in the comments by
// @vegito2002; this allows us to check the presence
// of the companion number (w.r.t. the prefix). Of course,
// @StefanPochmann's Python version of this algorithm is
// also amazingly concise -- I find @tangx668's solution
// a little easier to reverse engineer though.
//
// @tangx668's algortihm is O(n) time and O(n) space.
class Solution {
public:
  // Find the maximum XOR out of the numbers in sets [l1, r1) and [l2, r2).
  // These groups are assumed to be non-empty.
  int findMaximumXOR(std::vector<int> &nums, int l1, int r1, int l2, int r2,
                     unsigned bit) {

    // Sanity check. Shouldn't have non-empty sets.
    if (l1 == r1 || l2 == r2) {
      throw logic_error{"shouldn't happen"};
    }

    // One of the sets has one element. Try XORing between this element
    // and each element of the second set.
    if (l1 == r1 - 1 || l2 == r2 - 1) {
      int res{};
      for (; l1 < r1; ++l1) {
        for (int l2_{l2}; l2_ < r2; ++l2_) {
          res = std::max(res, nums[l1] ^ nums[l2_]);
        }
      }
      return res;
    }

    // Split sets on zeros and ones.
    int s1{l1}, s2{l2}, res{};
    while (s1 < r1 && !(nums[s1] & bit)) {
      ++s1;
    }
    while (s2 < r2 && !(nums[s2] & bit)) {
      ++s2;
    }

    bit >>= 1;

    // Try to cross over if possible.
    if (l1 != s1 && s2 != r2) {
      res = findMaximumXOR(nums, l1, s1, s2, r2, bit);
    }
    if (l2 != s2 && s1 != r1) {
      res = std::max(res, findMaximumXOR(nums, l2, s2, s1, r1, bit));
    }

    // Otherwise, the bits are all the same between the two groups.
    return res ? res : findMaximumXOR(nums, l1, r1, l2, r2, bit);
  }

  int findMaximumXOR(std::vector<int> &nums) {
    // Sort and deduplicate.
    std::sort(nums.begin(), nums.end());
    int j{};
    for (int i{}; i < nums.size(); ++i) {
      if (!i || nums[i] != nums[i - 1]) {
        nums[j++] = nums[i];
      }
    }

    // 0 or 1 elements means the XOR is automatically 0.
    if (j < 2) {
      return 0;
    }

    // Find first (largest) divergence bit.
    auto bit{1u << 31};
    while ((nums[0] & bit) == (nums[j - 1] & bit)) {
      bit >>= 1;
    }

    // Split into two (non-empty) groups.
    int s{};
    while (s < j && !(nums[s] & bit)) {
      ++s;
    }
    return findMaximumXOR(nums, 0, s, s, j, bit >> 1);
  }
};
