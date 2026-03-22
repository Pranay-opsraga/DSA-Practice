class Solution {
  public:
    bool detect (int src, vector<int>adjLs[], vector<int>&vis  ){
          vis[src] = 1;
          queue<pair<int, int>>q;
          q.push({src , -1});
          
          while(!q.empty()){
               int node = q.front().first;
               int parent = q.front().second;
               q.pop();
               
               for(auto it : adjLs[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push({it , node});
                    } else if (parent != it) {
                        return true;
                    }
               }
          }
          return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int>adjLs[V];
        
        for(auto &e : edges){
             int u = e[0];
             int v = e[1];
             
             adjLs[u].push_back(v);
             adjLs[v].push_back(u);
        }
        vector<int>vis(V, 0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(detect(i, adjLs, vis) == true) return true;
            }
        }
        return false;
    }
};
