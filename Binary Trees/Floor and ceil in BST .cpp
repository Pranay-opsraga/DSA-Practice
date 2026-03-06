/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
public:
	vector<int> floorCeilOfBST(TreeNode* root, int key){
		
		int ceil = -1;
		int floor = -1;
		
		while(root){
			
			if(root->data == key) 
                return {root->data , root->data};
			
			else if(root->data > key){
				ceil = root->data;
				root = root->left;
               
			} 
			
			else {
                floor = root->data;
				root = root->right;

			}
		}
		
		return {floor , ceil};
	}
};
