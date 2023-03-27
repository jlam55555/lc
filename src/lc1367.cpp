/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
public:
  // Idea: we can only skip nodes until we start matching the linked list.
  bool isSubPath(ListNode *head, TreeNode *root, bool started = false) {
    if (!head) {
      return true;
    }

    if (!root) {
      return false;
    }

    bool res{};
    if (head->val == root->val) {
      res = isSubPath(head->next, root->left, true) ||
            isSubPath(head->next, root->right, true);
    }
    if (!started) {
      res = res || isSubPath(head, root->left, false) ||
            isSubPath(head, root->right, false);
    }
    return res;
  }
};
