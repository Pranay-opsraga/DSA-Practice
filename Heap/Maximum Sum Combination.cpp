class Solution {
    public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
          int n = a.size();
         sort(a.begin(),a.end() , greater<int>());
         sort(b.begin(),b.end() , greater<int>());
          
         priority_queue<pair<int , pair<int,int>>>pq;
         set<pair<int,int>>visited;
         
         pq.push({a[0]+b[0] ,{0,0}});
         vector<int>res;
         visited.insert({0,0});
         
         while(k && !pq.empty()){
             auto top = pq.top();
             pq.pop();
             int sum = top.first;
             int i = top.second.first;
             int j = top.second.second;
             res.push_back(sum);
             
             if(i+1 < n && !visited.count({i+1 , j})){ //i+1
                 pq.push({a[i+1]+b[j] , {i+1,j}});
                 visited.insert({i+1 , j});
             }
             if(j+1 < n && !visited.count({i , j+1})){ //j+1
                 pq.push({a[i]+b[j+1] , {i,j+1}});
                 visited.insert({i , j+1});
             }
             k--;
         }
         
         return res;
    }
};
