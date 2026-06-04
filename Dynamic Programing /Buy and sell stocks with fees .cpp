// Memoization 

class Solution {
public:

    int solve(int i, int buy, vector<int>& prices, int fee,
              vector<vector<int>>& dp) {

        if (i == prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if (buy) {
            profit = max(
                -prices[i] + solve(i + 1, 0, prices, fee, dp),
                solve(i + 1, 1, prices, fee, dp)
            );
        }
        else {
            profit = max(
                prices[i] - fee + solve(i + 1, 1, prices, fee, dp),
                solve(i + 1, 0, prices, fee, dp)
            );
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, fee, dp);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {

            dp[i][1] = max(
                -prices[i] + dp[i + 1][0],
                dp[i + 1][1]
            );

            dp[i][0] = max(
                prices[i] - fee + dp[i + 1][1],
                dp[i + 1][0]
            );
        }

        return dp[0][1];
    }
};

// Space optimization

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        for (int i = prices.size() - 1; i >= 0; i--) {

            curr[1] = max(
                -prices[i] + ahead[0],
                ahead[1]
            );

            curr[0] = max(
                prices[i] - fee + ahead[1],
                ahead[0]
            );

            ahead = curr;
        }

        return ahead[1];
    }
};
