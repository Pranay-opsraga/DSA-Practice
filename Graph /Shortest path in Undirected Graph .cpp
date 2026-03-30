class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<int>dist(V , -1);
        
        vector<vector<int>>adj(V);
            
        for(auto e : edges){
             int u = e[0];
             int v = e[1];
             
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        
        queue<int>q;
        
        q.push(src);
        
        dist[src] = 0;
        
        while(!q.empty()){
              int node = q.front();
              q.pop();
              
              for(auto it : adj[node]){
                    if(dist[it] == -1){
                        dist[it] = 1 + dist[node];
                        q.push(it);
                    }
              }
              
              
        }
        return dist;
        
        
    }
};
