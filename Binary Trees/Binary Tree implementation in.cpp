#include <iostream>
using namespace std;

struct BT {
      int data;
      BT* left;
      BT* right;

      BT(int val){
           data = val;
           left = nullptr;
           right = nullptr;
      }
};

int main (){
      BT* root = new BT (10);
      root->left = new BT (20);
      root->right = new BT (30);

      root->left->right = new BT (40);
      root->left->left = new BT (50);

      root->right->left = new BT (60);
      root->right->right = new BT (70);

      root->left->left->left = new BT (80);
      root->left->left->right = new BT (90);

      root->right->left->left = new BT (100);
      root->right->left->right = new BT (110);

      root->right->right->left = new BT (120);
      root->right->right->right = new BT (130);

      return 0;
}

