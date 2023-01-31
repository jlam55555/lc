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
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
      return nullptr;
    }

    // Find middle element.
    ListNode sentinel{-1, head};
    auto it1 = head, it2 = head, prev = &sentinel;
    while (it2 && it2->next) {
      it1 = it1->next;
      prev = prev->next;
      it2 = it2->next->next;
    }

    // Middle element is tree root.
    prev->next = nullptr;
    return new TreeNode{it1->val, sortedListToBST(sentinel.next),
                        sortedListToBST(it1->next)};
  }
};
