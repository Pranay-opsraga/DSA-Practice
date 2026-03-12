/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv = p->val;
        int qv = q->val;

        TreeNode* curr = root;

        while (curr) {
            if(curr->val < min(pv , qv)){
                  curr = curr->right;
            } else if (curr->val > max(pv , qv)){
                 curr = curr->left;
            } else {
                  return curr;
            }
        }
        return nullptr;
    }
};
