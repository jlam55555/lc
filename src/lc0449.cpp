/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Encoding: Simple serialize it as such:
// root, [serialized left tree], [serialized right tree]
//
// For deserialization, we know that the left tree is done when
// we reach an element larger than the previous root.
class Codec {
public:
  // Helper function.
  std::string StrJoin(std::vector<int> &arr) {
    std::string res;
    for (auto i : arr) {
      res += std::to_string(i);
      res.push_back(',');
    }
    return res;
  }

  // Helper function.
  std::vector<int> StrSplit(std::string &s) {
    std::vector<int> res;
    for (int i{}, n(s.length()); i < n;) {
      int j{i + 1};
      while (s[j] != ',') {
        ++j;
      }
      res.push_back(std::stoi(s.substr(i, j - i)));
      i = j + 1;
    }
    return res;
  }

  // Helper function.
  void serialize(TreeNode *root, std::vector<int> &res) {
    if (!root) {
      return;
    }

    res.push_back(root->val);
    serialize(root->left, res);
    serialize(root->right, res);
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    std::vector<int> res;
    serialize(root, res);
    return StrJoin(res);
  }

  TreeNode *deserialize(const std::vector<int> &data, int &pos,
                        int stop = INT_MAX) {
    int n(data.size());
    if (pos == n || data[pos] > stop) {
      return nullptr;
    }

    auto *res{new TreeNode{data[pos]}};
    res->left = deserialize(data, ++pos, res->val);
    res->right = deserialize(data, pos, stop);
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    int pos{};
    return deserialize(StrSplit(data), pos);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
