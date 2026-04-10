class Solution {
    int timer = 1;
  public:
    void dfs(int node , int parent , vector<int>&tin , vector<int>&low , vector<int>&vis , vector<int>&mark , vector<vector<int>>&edges){
          vis[node] = 1;
          low[node] = tin[node] = timer;
          timer++;
          
          int child = 0;
          
          for(auto it : edges[node]){
                if(it == parent) continue;
                if(!vis[it]){
                     dfs(it , node , tin , low , vis , mark , edges);
                     low[node] = min(low[node] , low[it]);
                     if(low[it] >= tin[node] && parent != -1) mark[node] = 1;
                     child++;
                } else {
                     low[node] = min(low[node] , tin[it]);
                }
                
          }
          if(child > 1 && parent == -1) mark[node] = 1;
          
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
         vector<int>vis(V, 0);
         vector<int>tin (V , -1) , low(V , -1);
         vector<int>ans , mark(V , 0);
         vector<vector<int>>adj(V);
         
         for(auto it : edges){
              int u = it[0];
              int v = it[1];
              
              adj[u].push_back(v);
              adj[v].push_back(u);
         }
         
         for(int i = 0 ; i < V ; i++){
               if(!vis[i]){
                   dfs(i , -1 , tin , low , vis , mark , adj);
               }
         }
         
         for(int i = 0 ; i < V ; i++){
              if(mark[i] == 1) ans.push_back(i);
         }
         if(ans.size() == 0) return {-1};
         return ans;
        
    }
};
