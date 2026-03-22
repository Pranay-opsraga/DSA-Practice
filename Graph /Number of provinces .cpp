class Solution {
public:
    void dfs (vector<vector<int>>& isConnected , int node , vector<int>&vis){
           vis[node] = 1;

           for(int j = 0 ; j < isConnected.size() ; j++){
                if(isConnected[node][j] == 1 && !vis[j] ){
                      dfs(isConnected , j , vis);
                }
           }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, i, vis);
                cnt++;
            }
        }
        return cnt;
    }
};
