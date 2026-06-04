// Memoization

class Solution {
public:
    using ull = unsigned long long;
    int solve(int ind, int buy, int cap, vector<int>& prices,
              vector<vector<vector<ull>>>& dp) {
        if (cap == 0)
            return 0;

        if (ind == prices.size())
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        ull profit = 0;
        if (buy) {
            profit = max(-prices[ind] + solve(ind + 1, 0, cap, prices, dp),
                         solve(ind + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[ind] + solve(ind + 1, 1, cap - 1, prices, dp),
                         solve(ind + 1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<ull>>>dp(
            n, vector<vector<ull>>(2, vector<ull>(k+1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 1; cap <= k; cap++) {

                dp[ind][1][cap] = max(-prices[ind] + dp[ind + 1][0][cap],
                                      dp[ind + 1][1][cap]);

                dp[ind][0][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                      dp[ind + 1][0][cap]);
            }
        }

        return dp[0][1][k];
    }
};

// space optimization

class Solution {
public:
    using ll = long long;
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<ll>> curr(2, vector<ll>(k+1, 0));
        vector<vector<ll>> ahead(2, vector<ll>(k+1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 1; cap <= k; cap++) {

                curr[1][cap] = max(-prices[ind] + ahead[0][cap], ahead[1][cap]);

                curr[0][cap] =
                    max(prices[ind] + ahead[1][cap - 1], ahead[0][cap]);
            }
            ahead = curr;
        }

        return ahead[1][k];
    }
};
