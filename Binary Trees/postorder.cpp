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
   void dfs(TreeNode* root , vector<int>&ans){
          
          if(root == nullptr) return; //Base Case

          dfs(root->left , ans);
          dfs(root->right , ans);
          ans.push_back(root->val);
          return ;
    }
    vector<int> postorderTraversal(TreeNode* root) {
           
           vector<int>ans;
           dfs(root , ans);
           return ans;
    }
};
