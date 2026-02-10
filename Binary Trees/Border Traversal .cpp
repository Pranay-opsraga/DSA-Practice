/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:

    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    void leftBoundry(TreeNode* root , vector<int>& res){
        TreeNode* curr = root->left;

        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void rightBoundry(TreeNode* root , vector<int>& res){
        TreeNode* curr = root->right;
        vector<int> temp;

        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }

        // reverse order
        for(int i = temp.size() - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode* root , vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }

        if(root->left) addLeaves(root->left , res);
        if(root->right) addLeaves(root->right , res);
    }
    
    vector<int> boundary(TreeNode* root){
        vector<int> res;

        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);

        leftBoundry(root , res);
        addLeaves(root , res);
        rightBoundry(root , res);

        return res;
    }
};
