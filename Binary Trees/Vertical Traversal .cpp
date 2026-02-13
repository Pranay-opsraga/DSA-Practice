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

    void dfs (TreeNode* root , int col , int row , vector<tuple<int,int,int>>&nodes){
            
            if(!root) return;

            nodes.push_back({col , row , root->val});

            dfs(root->left , col-1 , row+1 , nodes);
            dfs(root->right , col+1 , row+1 , nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          
           vector<tuple<int,int,int>>nodes;
           dfs(root , 0 , 0 , nodes);

           vector<vector<int>>ans;

           sort(nodes.begin() , nodes.end());
           int prev_col = INT_MIN;

           for(auto& [col , row , val] : nodes){
                  if(prev_col != col){
                      ans.push_back({});
                      prev_col = col;
                  }
                  ans.back().push_back(val);
           }
         return ans;  
    }
};
