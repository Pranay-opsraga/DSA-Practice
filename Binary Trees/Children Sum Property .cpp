/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        
         if(!root) return true;

         queue<TreeNode*>q;
         q.push(root);

         while(!q.empty()){
             int size = q.size();

             for(int i = 0 ; i < size ; i++){
                  TreeNode* node = q.front();
                  q.pop();

                  if(node->left) q.push(node->left);
                  if(node->right) q.push(node->right);

                  if(!node->left && !node->right) continue;

                 int leftVal  = node->left  ? node->left->val  : 0;
                 int rightVal = node->right ? node->right->val : 0;

                 if(node->val != leftVal + rightVal)
                 return false;
             }
         }
         return true;
    }
};
