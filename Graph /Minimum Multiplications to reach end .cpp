// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
         int mod = 100000;
         queue<pair<int,int>>q;
         vector<int>dist(mod , INT_MAX);
         
         q.push({0 , start});
         dist[start] = 0;
         while(!q.empty()){
               auto [ steps , node ] = q.front();
               q.pop();
               
               if(node == end) return steps;
               
               for(auto it : arr){
                    int newNode = (it * node) % mod;
                    if(steps+1 < dist[newNode]){
                         dist[newNode] = steps+1;
                         q.push({dist[newNode] , newNode});
                    }
               }
               
         }
         return -1;
        
    }
};
