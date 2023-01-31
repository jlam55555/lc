/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) {
      return "[]";
    }

    string res = "[";

    queue<TreeNode *> q{};
    q.push(root);
    int found = 0, prev_found;
    while (found >= 0) {
      prev_found = found;
      found = -1;
      int s = q.size();
      for (int i = 0; i <= s && !q.empty(); ++i) {
        auto t = q.front();
        q.pop();

        if (!t) {
          res += "null,";
          continue;
        }

        res += to_string(t->val) + ",";
        if (t->left) {
          found = 2 * i;
        }
        if (t->right) {
          found = 2 * i + 1;
        }
        q.push(t->left);
        q.push(t->right);
      }
    }

    return res.substr(0, res.length() - 1) + "]";
  }

  vector<string> str_split(string s, char delim) {
    int prev = 0, pos;
    vector<string> res{};
    while ((pos = s.find(delim, prev)) != -1) {
      res.push_back(s.substr(prev, pos - prev));
      prev = pos + 1;
    }
    res.push_back(s.substr(prev, pos - prev));
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    int i = 0;
    vector<string> cells = str_split(data.substr(1, data.length() - 2), ',');

    if (cells.size() == 1 && cells[0] == "") {
      return nullptr;
    }

    vector<TreeNode *> curRow{}, nextRow{};
    int j = 1;

    curRow.push_back(new TreeNode{stoi(cells[0]), nullptr, nullptr});
    TreeNode *root = curRow[0];

    while (j < cells.size()) {
      for (int i = 0; j < cells.size() && i < 2 * curRow.size(); ++i, ++j) {
        if (cells[j] != "null") {
          TreeNode *newNode = new TreeNode{stoi(cells[j]), nullptr, nullptr};
          nextRow.push_back(newNode);
          if (i % 2 == 0) {
            curRow[i / 2]->left = newNode;
          } else {
            curRow[i / 2]->right = newNode;
          }
        }
      }
      swap(curRow, nextRow);
      nextRow = {};
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
