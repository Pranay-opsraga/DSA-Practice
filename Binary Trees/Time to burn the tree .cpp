/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent,
             int start, TreeNode*& startNode) {
        if (!root)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == start)
                    startNode = node;

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node;
                     q.push(node->right);
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = nullptr;
        bfs(root, parent, start, startNode);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = true;
        int minute = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                    spread = true;
                }
                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                    spread = true;
                }
                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                    spread = true;
                }
            }
            if (spread)
                minute++;
        }
        return minute;
    }
};
