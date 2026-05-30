// Memoization

class Solution {
public:
    int solve(int ind, int target, vector<int>& coins,
              vector<vector<int>>& dp) {

        if (target == 0) return 0;

        if (ind == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notake = solve(ind - 1, target, coins, dp);

        int take = 1e9;
        if (coins[ind] <= target)
            take = 1 + solve(ind, target - coins[ind], coins, dp);

        return dp[ind][target] = min(notake, take);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};

// Tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {

                int notake = 0 + dp[i - 1][j];

                int take = 1e9;

                if (coins[i] <= j)
                    take = 1 + dp[i][j - coins[i]];

                dp[i][j] = min(take, notake);
            }
        }
        int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};

// space optimization

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

         vector<int>dp(amount + 1, 0);

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[target] = target / coins[0];
            else
                dp[target] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {

                int notake = 0 + dp[j];

                int take = 1e9;

                if (coins[i] <= j)
                    take = 1 + dp[j - coins[i]];

                dp[j] = min(take, notake);
            }
        }
        int ans = dp[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};
