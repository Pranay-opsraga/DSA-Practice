class Solution {
  public:
    vector<int> topo(int n , vector<vector<int>>&adj){
            vector<int>indegree(n , 0);
            
            for(int i = 0 ; i < n ; i++){
                  for(auto it : adj[i]){
                        indegree[it]++;
                  }
            }
            
            stack<int>st;
            
            for(int i = 0 ; i < n ; i++){
                  if(indegree[i] == 0) st.push(i);
            }
            
            vector<int>topo;
            
            while(!st.empty()){
                  int node = st.top();
                  st.pop();
                  
                  topo.push_back(node);
                  
                  for(auto it : adj[node]){
                       indegree[it]--;
                       if(indegree[it] == 0) st.push(it);
                       
                  }
            }
            return topo;
    }
    string findOrder(vector<string> &words) {
         unordered_map<char , int>mpp;
         int idx = 0;
         
         for(auto word : words){
             for(auto ch : word){
                 if(mpp.find(ch) == mpp.end()){
                      mpp[ch] = idx++;
                 }
             }
         }
         int n = mpp.size();
         
         vector<vector<int>>adj(n);
         
         for(int i = 0 ; i < words.size() - 1 ; i++){
               string s1 = words[i];
               string s2 = words[i+1];
               int found = false;
               int len = min(s1.size() , s2.size());
               for(int ptr = 0 ; ptr < len ; ptr++){
                      if(s1[ptr] != s2[ptr]){ 
                      found = true;
                      adj[mpp[s1[ptr]]].push_back(mpp[s2[ptr]]);
                      break;
                      }
                      
               }
               if(!found && s1.size() > s2.size() ){
                           return "";
                }
               
         }
         
         vector<int>ans = topo(n , adj);
         string res = "";
         if(ans.size() != n) return "";
         vector<char>rev(n);
         for(auto it : mpp){
               rev[it.second] = it.first;
         }
         for(auto it : ans){
               res = res + rev[it];
         }
         return res;
        
    }
};
