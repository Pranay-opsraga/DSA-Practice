// Greedy method 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

// Memoization

class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(i + 1, 0, prices, dp),
                         solve(i + 1, 1, prices, dp));
        } else {
            profit = max(prices[i] + solve(i + 1, 1, prices, dp),
                         solve(i + 1, 0, prices, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {

            dp[ind][1] = max(
                -prices[ind] + dp[ind + 1][0], 
                dp[ind + 1][1]                 
            );

            dp[ind][0] = max(
                prices[ind] + dp[ind + 1][1], 
                dp[ind + 1][0]                
            );
        }

        return dp[0][1];
    }
};

// space optimization (2D)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int>curr(2, 0);
        vector<int>ahead(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {

            curr[1] = max(
                -prices[ind] + ahead[0], 
                ahead[1]                
            );

            curr[0] = max(
                prices[ind] + ahead[1], 
                ahead[0]                
            );
            ahead = curr;
        }

        return dp[0][1];
    }
};

// space optimization (1D)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int aheadBuy = 0, aheadSell = 0;

        for (int ind = prices.size() - 1; ind >= 0; ind--) {

            int currBuy = max(
                -prices[ind] + aheadSell,
                aheadBuy
            );

            int currSell = max(
                prices[ind] + aheadBuy,
                aheadSell
            );

            aheadBuy = currBuy;
            aheadSell = currSell;
        }

        return aheadBuy;
    }
};
