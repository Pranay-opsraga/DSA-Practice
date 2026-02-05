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
    vector<int> postorderTraversal(TreeNode* root) {
         
          stack<TreeNode*>st;
          TreeNode* lastvisited = nullptr;
          TreeNode* curr = root;
          vector<int>arr;
          if (root == nullptr) return arr;


         while (curr != nullptr || !st.empty()){
               
               while(curr != nullptr){
                    
                    st.push(curr);
                    curr = curr->left;
               }

               TreeNode* node = st.top();

               if(node->right != nullptr && node->right != lastvisited){
                        curr = node->right;
               }
               else {
                    
                    arr.push_back(node->val);
                    lastvisited = node;
                    st.pop();
               }
          }
          return arr;
    }
};
