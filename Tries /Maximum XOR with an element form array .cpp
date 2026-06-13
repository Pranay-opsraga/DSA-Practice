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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
          int n = nums.size();
          sort(nums.begin() , nums.end());

          vector<pair<int, pair<int,int>>>q;

          for(int i = 0 ; i < queries.size() ; i++){
                 q.push_back({queries[i][1] , {queries[i][0] , i}});
          }

          sort(q.begin() , q.end());
          int ind = 0;
          Trie trie;
          vector<int>ans(queries.size() , 0);

          for(auto &it : q){
               int xi = it.second.first;
               int mi = it.first;
               int Qind = it.second.second;
               while( ind < n && nums[ind] <= mi){
                    trie.insert(nums[ind]);
                    ind++;
               }
               if(ind == 0) ans[Qind] = -1;
               else ans[Qind] = trie.getMax(xi);
          }
          return ans;
    }
};
