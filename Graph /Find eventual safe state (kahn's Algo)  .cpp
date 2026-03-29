class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        stack<int>st;

        for(int i = 0;  i < n ; i++){
              for(auto g : graph[i]){
                  adj[g].push_back(i);
              }
        }

        vector<int>outdegree(n , 0);

        for(int i = 0; i < n ; i++){
            for(auto it : adj[i]){
                   outdegree[it]++;
            }
        }

        for(int i = 0 ; i < n ; i++){
              if(outdegree[i] == 0) st.push(i);
        }

        
        vector<int>ans;

        while(!st.empty()){
               int node = st.top();
               st.pop();

               ans.push_back(node);

               for(auto it : adj[node]){
                    outdegree[it]--;
                    if(outdegree[it] == 0) st.push(it);
               }
        }

        sort(ans.begin() , ans.end());
        return ans;

    }
};
