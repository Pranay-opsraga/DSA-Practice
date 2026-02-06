/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        vector<int> pre, inn, post;

        while(!st.empty()) {

            auto it = st.top();
            st.pop();

            // Preorder
            if(it.second == 1) {

                pre.push_back(it.first->data);
                it.second++;
                st.push(it);

                if(it.first->left != nullptr) {
                    st.push({it.first->left, 1});
                }
            }

            // Inorder
            else if(it.second == 2) {

                inn.push_back(it.first->data);
                it.second++;
                st.push(it);

                if(it.first->right != nullptr) {
                    st.push({it.first->right, 1});
                }
            }

            // Postorder
            else {
                post.push_back(it.first->data);
            }
        }

        ans.push_back(inn);
        ans.push_back(pre);
        ans.push_back(post);

        return ans;
    }
};
