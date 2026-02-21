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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int total = 0;

        while (!q.empty()) {
            int size = q.size();
            int width = 0;

            long long first = q.front().second;
            long long last = first;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second - first;
                q.pop();

                last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx+1});
                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            width = last + 1;
            total = max(total, width);
        }
        return total;
    }
};
