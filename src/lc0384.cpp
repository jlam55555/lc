class Solution {
  std::vector<int> original_;

public:
  Solution(vector<int> &nums) : original_{nums} {}

  vector<int> reset() { return original_; }

  // Fisher-Yates in-place shuffling algorithm.
  vector<int> shuffle() {
    auto res{original_};
    int N(res.size());
    for (int i{}; i < N; ++i) {
      // Randomly choose from the rightmost N-i elements,
      // put this at position i.
      std::swap(res[i], res[i + (std::rand() % (N - i))]);
    }
    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
