/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        queue<TreeNode*> q;
        string s = "";
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                s += "#,";
            } else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            getline(ss, str, ',');
            if (str == "#") {
                node->left = nullptr;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Right child
            getline(ss, str, ',');
            if (str == "#") {
                node->right = nullptr;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
