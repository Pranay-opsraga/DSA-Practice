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
    

    int helper(TreeNode* root , int& res) {

        if (root == nullptr)
            return 0;

        int lhsum = max( 0 , helper(root->left , res));
        int rhsum = max(0 , helper(root->right, res));

        res = max(res, lhsum + rhsum + root->val);

        return root->val + max(lhsum, rhsum);
    }
    int maxPathSum(TreeNode* root) {
        int sum = root->val;

        helper(root , sum);
        return sum;
    }
};
