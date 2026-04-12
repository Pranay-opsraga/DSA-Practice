// Memoization 
class Solution {
  public:
    int solve(int x, vector<int>& height , vector<int>&dp){
    if(x == height.size() - 1) return 0;
    
    if(dp[x] != -1) return dp[x];

    int fs = solve(x + 1, height , dp) + abs(height[x] - height[x+1]);

    int ss = INT_MAX;
    if(x + 2 < height.size())
        ss = solve(x + 2, height , dp) + abs(height[x] - height[x+2]);

    return dp[x] = min(fs, ss);
}

    int minCost(vector<int>& height) {
      int n = height.size();
      vector<int>dp(n+1 , -1);  
      return solve(0, height , dp);
    }
};

// Tabulation
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n+1 , -1);
        dp[0] = 0;
       
        for(int i = 1; i <= n ; i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i > 1) ss = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(fs , ss);
            
        }
        return dp[n-1];
        
    }
};

// Space optimization
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        
       int prev = 0;
       int prev2 = 0;
        for(int i = 1; i <  n ; i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i > 1) ss = prev2 + abs(height[i] - height[i-2]);
            
            int curr = min(fs , ss);
            prev2 = prev;
            prev = curr;
        }
        return prev;
        
    }
};
