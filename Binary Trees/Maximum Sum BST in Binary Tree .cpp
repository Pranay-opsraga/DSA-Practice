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
    int ans = 0;
    struct Para {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
    Para dfs(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Para left = dfs(root->left);
        Para right = dfs(root->right);

        if (left.isBST && right.isBST && left.maxVal < root->val &&
            right.minVal > root->val) {
            int currsum = left.sum + right.sum + root->val;
            ans = max(ans, currsum);

            return {true, currsum, min(root->val, left.minVal),
                    max(root->val, right.maxVal)};
        }

        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
