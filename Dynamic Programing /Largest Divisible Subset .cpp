class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         
         int n = nums.size();
         sort(nums.begin() , nums.end());
         vector<int>dp(n , 1);
         vector<int>parent(n);
         int maxi = 1;
         int lastIndex = 0;
         for(int i = 0 ; i < n ; i++){
            parent[i] = i;
             for(int prev = 0 ; prev < i ; prev++){
                  
                  if((nums[i] % nums[prev]) == 0 && dp[prev] + 1 > dp[i]){
                      dp[i] = dp[prev]+1;
                      parent[i] = prev;
                  }
             }

             if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
             }
         }
        vector<int>temp;
         while(parent[lastIndex] != lastIndex){
                temp.push_back(nums[lastIndex]);
                lastIndex = parent[lastIndex];
         }
         temp.push_back(nums[lastIndex]);

         reverse(temp.begin() , temp.end());
         return temp;

    }
};
