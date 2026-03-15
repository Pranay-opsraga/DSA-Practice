/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        
        vector<Node*>res;
        if(!root) return res;
        Node* pre = nullptr;
        Node* succ = nullptr;
        
        while(root){
             if(key > root->data){
                   pre = root;
                   root = root->right;
             } else if(key < root->data) {
                  succ = root;
                  root = root->left;
             } else {
                  if(root->left){
                       Node* temp = root->left;
                       while(temp->right) temp = temp->right;
                       pre = temp;
                  }
                  
                  if(root->right){
                       Node* temp = root->right;
                       while(temp->left) temp = temp->left;
                       succ = temp;
                  }
                  break;
             }
             
        }
        
        return{pre, succ};
        
    }
};
