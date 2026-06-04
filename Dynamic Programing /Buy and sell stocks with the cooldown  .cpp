// Memoization

class Solution {
public:
    
    int solve(int i, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {
        
        int n = prices.size();
        
        if (i >= n) return 0;
        
        if (dp[i][buy] != -1)
            return dp[i][buy];
        
        int profit = 0;
        
        if (buy) {
            profit = max(
                -prices[i] + solve(i + 1, 0, prices, dp), 
                solve(i + 1, 1, prices, dp)              
            );
        }
        else {
            profit = max(
                prices[i] + solve(i + 2, 1, prices, dp), 
                solve(i + 1, 0, prices, dp)              
            );
        }
        
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return solve(0, 1, prices, dp);
    }
};

// Tabultion

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
          int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {

            dp[ind][1] = max(
                -prices[ind] + dp[ind + 1][0], 
                dp[ind + 1][1]                 
            );

            dp[ind][0] = max(
                prices[ind] + dp[ind + 2][1], 
                dp[ind + 1][0]                
            );
        }

        return dp[0][1];
         
    }
};

// Space optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> ahead1(2, 0);
        vector<int> ahead2(2, 0); 
        vector<int> curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {

            curr[1] = max(
                -prices[i] + ahead1[0],
                ahead1[1]
            );

            curr[0] = max(
                prices[i] + ahead2[1],
                ahead1[0]
            );

            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[1];
    }
};
