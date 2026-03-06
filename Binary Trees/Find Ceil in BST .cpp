class Solution {
  public:
    int findCeil(Node* root, int x) {
        
        int ceilNode = -1;
        
        while(root){
              if(root->data == x) return root->data;
              else if (root->data > x){
                   
                       ceilNode = root->data;
                       root = root->left;
                   
              } else {
                  
                      root = root->right;
                      
              
         }
    
     }
       return ceilNode;  
    }

};
