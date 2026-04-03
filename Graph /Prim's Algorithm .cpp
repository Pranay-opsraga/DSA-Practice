class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
          
          vector<int>vis(V , 0);
          priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
          pq.push({0 , 0});
          int sum = 0;
          
          vector<vector<pair<int,int>>>adj(V);
          for(auto e : edges){
              int u = e[0];
              int v = e[1];
              int w = e[2];
              adj[u].push_back({v , w});
              adj[v].push_back({u , w});
              
          }
          
          while(!pq.empty()){
                auto [ wt , node] = pq.top();
                pq.pop();
                
                if(vis[node] == 1) continue;
                vis[node] = 1;
                sum += wt;
                
                for(auto it : adj[node]){
                      int adjNode = it.first;
                      int adjwt = it.second;
                      
                      if(!vis[adjNode]){
                           pq.push({adjwt , adjNode});
                      }
                }
          }
          return sum;
        
    }
};
