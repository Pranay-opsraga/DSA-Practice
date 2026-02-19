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
    bool isleaf(TreeNode* root){
         return (!root->left && !root->right); 
    } 

    void dfs(TreeNode* root, string&path, vector<string>& ans) {

        int len = path.size(); 

        path += to_string(root->val); 

        if (isleaf(root)) {
            ans.push_back(path);
        } else {
            path += "->"; 

            if (root->left)
                dfs(root->left, path, ans);
            if (root->right)
                dfs(root->right, path, ans);
        }

        path.resize(len);
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        if (!root)
            return ans;

        string path;
        dfs(root, path, ans);
        return ans;
    }
};
