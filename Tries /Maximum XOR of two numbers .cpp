struct Node {
    Node* links[2];

    bool containskey(int x) { return (links[x] != NULL); }

    void put(int x, Node* node) { links[x] = node; }

    Node* get(int x) { return links[x]; }
};

class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int x) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if(!node->containskey(bit)){
                node->put(bit, new Node());
            }
           node = node->get(bit);
        }
    }

    int getMax(int x) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if(node->containskey(1 - bit)){
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
         Trie trie;

         for(int &num : nums){
            trie.insert(num);
         }

         int ans = 0;

         for(int &num : nums){
            ans = max(ans , trie.getMax(num));
         }
         return ans;
    }
};
