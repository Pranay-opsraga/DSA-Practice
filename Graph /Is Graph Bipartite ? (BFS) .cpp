class Solution {
public:
    bool bfs(int start , vector<int>&color , vector<vector<int>>&adj){
           queue<int>q;
           q.push(start);
           
           while(!q.empty()){
               int node = q.front();
               q.pop();

               for(auto it : adj[node]){

                   if(color[it] == -1){
                   color[it] = 1 - color[node];
                   q.push(it);
                   }
                    else if (color[it] == color[node]){
                          return false;
                    }
               }
           }
           return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {

          int n = graph.size();

          vector<int>color(n);

          for(int i = 0 ; i < n ; i++){
              color[i] = -1;
          }

          for(int i = 0 ; i < n ; i++){
               if(color[i] == -1){
                   if(bfs( i , color , graph) == false) return false;
               }
          }
          return true;
    }
};
