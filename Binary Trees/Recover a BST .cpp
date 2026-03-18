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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void dfs(TreeNode* root) {
        if (!root)
            return;

        TreeNode* curr = root;

        while (curr) {

            if (curr->left == nullptr) {

                if (prev && prev->val > curr->val) {
                    if (!first)
                        first = prev;
                    second = curr;
                }
                prev = curr;

                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;

                while (temp->right && temp->right != curr) {
                    temp = temp->right;
                }

                if (temp->right == nullptr) {
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    temp->right = nullptr;

                    if (prev && prev->val > curr->val) {
                        if (!first)
                            first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};
