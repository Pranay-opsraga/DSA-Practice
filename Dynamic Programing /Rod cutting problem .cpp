// Memoization

class Solution {
  public:
    int solve(int ind , int len , vector<int>&price ,  vector<vector<int>>&dp ){
          if(ind == 0) return len* price[0];
          
          if(dp[ind][len] != -1) return dp[ind][len];
          
          int nottake = 0 + solve(ind-1 , len , price , dp);
          int take = 0;
          
          int rodlen = ind+1;
          if(rodlen <= len) take = price[ind] + solve(ind , len-rodlen , price, dp);
          
          return dp[ind][len] = max(nottake , take);
    }
    int cutRod(vector<int> &price) {
        
        int n = price.size();
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return solve(n-1 , n , price , dp);
        
    }
};

// Tabulation

class Solution {
  public:

    int cutRod(vector<int> &price) {
        
        int n = price.size();
        vector<vector<int>>dp(n , vector<int>(n+1 , 0));
        
        for(int len = 0 ; len <= n ; len++){
            dp[0][len] = len * price[0];
        }
        
        for (int ind = 1; ind < n; ind++) {
            int rodLen = ind + 1;

            for (int len = 0; len <= n; len++) {

                int notTake = dp[ind - 1][len];

                int take = 0;
                if (rodLen <= len) {
                    take = price[ind] +
                           dp[ind][len - rodLen];
                }

                dp[ind][len] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
        
};

// Space optimization

// User function Template for C++

class Solution {
  public:

    int cutRod(vector<int> &price) {
        
        int n = price.size();
        vector<int>dp(n+1 , 0);
        
        for(int len = 0 ; len <= n ; len++){
            dp[len] = len * price[0];
        }
        
        for (int ind = 1; ind < n; ind++) {
            int rodLen = ind + 1;

            for (int len = 0; len <= n; len++) {

                int notTake = dp[len];

                int take = 0;
                if (rodLen <= len) {
                    take = price[ind] +
                           dp[len - rodLen];
                }

                dp[len] = max(take, notTake);
            }
        }

        return dp[n];
    }
        
};
