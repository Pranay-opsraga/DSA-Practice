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

   void solve(TreeNode* root , vector<int>&ans){
            if(!root) return ;

            solve(root->left , ans);
            ans.push_back(root->val);
            solve(root->right , ans);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return false;
         vector<int>arr;
         solve(root , arr);

         for(int i = 1 ; i < arr.size() ; i++){
              if(arr[i-1] >= arr[i]) return false;
         }
         return true;
    }
};
