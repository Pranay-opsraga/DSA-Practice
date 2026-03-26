class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
          queue<int>q;
          int indirect[V] = {0};
          
          vector<vector<int>>adj(V);
          
          for(auto e : edges){
              int u = e[0];
              int v = e[1];
              
              adj[u].push_back(v);
          }
          
          for(int i = 0 ; i < V ; i++){
               for(auto it : adj[i]){
                   indirect[it]++;
               }
          }
          
          for(int i = 0 ; i < V ; i++){
              if(indirect[i] == 0){
                   q.push(i);
              }
          }
          
          vector<int>topo;
          
          while(!q.empty()){
                int node = q.front();
                q.pop();
                
                topo.push_back(node);
                
                for(auto it : adj[node]){
                     indirect[it]--;
                     if(indirect[it] == 0) q.push(it);
                }
          }
          return topo;
        
    }
};
