/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        int check = 0;

        while (!q.empty()) {
            int Size = q.size();
            vector<int> arr;

            for (int i = 0; i < Size; i++) {
                TreeNode* node = q.front();
                q.pop();

                arr.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (check & 1) {
                reverse(arr.begin(), arr.end());
            }

            ans.push_back(arr);
            check ^= 1;   
        }

        return ans;
    }
};
