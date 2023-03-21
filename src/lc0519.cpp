// This is basically a 2-D online Fisher-Yates shuffling
// algorithm. This uses a std::unordered_map<int, int> rather
// than a std::vector<int> to efficiently handle sparse matrices.
// This optimization for sparse matrices is borrowed from
// @BingleLove's solution.
class Solution {
  const int m_, n_, size_;
  int pos_;
  std::unordered_map<int, int> shuffle_;

public:
  Solution(int m, int n) : m_{m}, n_{n}, size_{m * n} { reset(); }

  vector<int> flip() {
    // Swap pos_ with to_swap. Some ugly handling is necessary
    // for default values.
    int res, to_swap{pos_ + std::rand() % (size_ - pos_)};
    auto it1{shuffle_.find(pos_)}, it2{shuffle_.find(to_swap)};
    res = it2 == shuffle_.end() ? to_swap : it2->second;
    shuffle_[to_swap] = it1 == shuffle_.end() ? pos_ : it1->second;
    ++pos_;
    return {res / n_, res % n_};
  }

  void reset() {
    pos_ = 0;
    shuffle_.clear();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
