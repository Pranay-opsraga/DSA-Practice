// Memoization

class Solution {
public:
    int solve(int i, int buy, int cap ,  vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (i == prices.size())
            return 0;

        if(cap == 0) return 0; 

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(i + 1, 0, cap,  prices, dp),
                         solve(i + 1, 1, cap , prices, dp));
        } else {
            profit = max(prices[i] + solve(i + 1, 1, cap-1 ,  prices, dp),
                         solve(i + 1, 0, cap ,  prices, dp));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        return solve(0, 1, 2 ,  prices, dp);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 1; cap <= 2; cap++) {

                dp[ind][1][cap] = max(-prices[ind] + dp[ind + 1][0][cap],
                                      dp[ind + 1][1][cap]);

                dp[ind][0][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                      dp[ind + 1][0][cap]);
            }
        }

        return dp[0][1][2];
    }
};

// space optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> ahead(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 1; cap <= 2; cap++) {

                curr[1][cap] = max(-prices[ind] + ahead[0][cap],
                                      ahead[1][cap]);

                curr[0][cap] = max(prices[ind] + ahead[1][cap - 1],
                                      ahead[0][cap]);
            }
            ahead = curr;
        }

        return ahead[1][2];
    }
};
