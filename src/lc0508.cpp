/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  std::unordered_map<int, int> freqs_;
  int max_freq_{INT_MIN};

public:
  int CountSubtreeSums(TreeNode *root) {
    if (!root) {
      return 0;
    }

    auto total_sum{root->val + CountSubtreeSums(root->left) +
                   CountSubtreeSums(root->right)};
    max_freq_ = std::max({max_freq_, ++freqs_[total_sum]});
    return total_sum;
  }

  vector<int> findFrequentTreeSum(TreeNode *root) {
    CountSubtreeSums(root);

    std::vector<int> res;
    for (auto [val, freq] : freqs_) {
      if (freq == max_freq_) {
        res.push_back(val);
      }
    }
    return res;
  }
};
