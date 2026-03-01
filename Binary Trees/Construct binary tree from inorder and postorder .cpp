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
    TreeNode* build(vector<int>& postorder, int pstart, int pend,
                    vector<int>& inorder, int istart, int iend,
                    unordered_map<int, int>& mpp) {

        if (pstart > pend || istart > iend)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[pend]);
        int inroot = mpp[root->val];
        int numsLeft = inroot - istart;

        root->right = build(postorder, pstart + numsLeft, pend - 1, inorder,
                            inroot + 1, iend, mpp);

        root->left = build(postorder, pstart, pstart + numsLeft - 1, inorder,
                           istart, inroot - 1, mpp);

          return root;                 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = build(postorder, 0, postorder.size() - 1, inorder, 0,
                               inorder.size() - 1, mpp);

        return root;
    }
};
