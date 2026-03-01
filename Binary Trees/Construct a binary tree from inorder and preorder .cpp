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
    TreeNode* solve(vector<int>& preorder, int pstart, int pend,
                    vector<int>& inorder, int istart, int iend,
                    unordered_map<int, int>& mpp) {
        if (pstart > pend || istart > iend) return nullptr;

        TreeNode* root = new TreeNode(preorder[pstart]);

        int inroot = mpp[root->val];
        int numsLeft = inroot - istart;

        root->left = solve(preorder, pstart + 1, pstart + numsLeft, inorder,
                           istart, inroot - 1, mpp);
        root->right = solve(preorder, pstart + 1 + numsLeft, pend, inorder,
                            inroot + 1, iend, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = solve(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1, mpp);
        return root;
    }
};
