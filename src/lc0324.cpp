// Easy way: sort and then interleave in a new array. O(N*log(N)) time,
// O(N) space.
//
// We can make this O(N) time by turning the sort into a quickselect; this
// allows us to partition the array. Note that we actually need to partition
// the array in three ways, because the median element may cause troubles
// if we don't, so this is probably a two step approach: quickselect the
// median element, and then do a Dutch flag sort.
//
// We can make this O(1) space by doing the interleaving in place rather
// than creating a new array. It seems that a method for doing this is
// surprisingly non-trivial: https://cs.stackexchange.com/questions/332.
// Thus we look for a way in which we don't have to strictly maintain
// the order of the elements; see Pochmann's algorithm.
//
// Genius way: Pochmann's solution to this. (Usually Pochmann's solutions
// are already amazing, but this one is one of the best.) The idea is
// that we find the median, and then do a 3-way (Dutch flag) partitioning
// in the "virtual address space" of [1, 3, ..., N-1, 0, 2, ..., N]
// even N and [1, 3, ..., N, 0, 2, ..., N-1] for odd N. The reason
// for doing the Dutch flag partitioning is that we need to make sure that
// the median elements are grouped together, or else they may appear next
// to one another in the result.
//
// This solution is basically copied from Pochmann's solution. There's
// really not much I could improve on that solution. I also learned about
// the std::nth_element() function.
class Solution {
public:
  // Map indices from the Dutch-flag-sorted array into the final indices
  // as described above.
  int Map(int N, int i) { return (1 + (i << 1)) % (N | 1); }

  void wiggleSort(vector<int> &nums) {
    int N(nums.size());

    // Find the median.
    auto median_it = nums.begin() + (N >> 1);
    std::nth_element(nums.begin(), median_it, nums.end());
    auto median = *median_it;

#define A(i) nums[Map(N, (i))]

    // Dutch flag sort on the virtual address space.
    int i{}, j{}, k{N - 1};
    while (j <= k) {
      if (A(j) > median) {
        std::swap(A(i++), A(j++));
      } else if (A(j) < median) {
        std::swap(A(k--), A(j));
      } else {
        ++j;
      }
    }

#undef A
  }
};
