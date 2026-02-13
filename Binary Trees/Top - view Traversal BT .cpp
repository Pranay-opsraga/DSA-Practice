/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        
         if(!root) return {};

         map<int,int>mpp; // col -> value
         queue<pair<Node* , int>>q;
         q.push({root , 0});

         while(!q.empty()){
              auto [node , col] = q.front();
              q.pop();

              if(mpp.find(col) == mpp.end()){
                    mpp[col] = node->data;
              }

              if(node->left) q.push({node->left , col-1 });
              if(node->right) q.push({node->right , col+1});
         }

         vector<int>ans;

         for(auto &x : mpp){
             ans.push_back(x.second); 
         }

         return ans;
        
    }
};
