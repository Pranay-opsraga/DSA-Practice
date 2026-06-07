// Memoization

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int k = i; k <= j; k++) {
            int cost = (cuts[j + 1] - cuts[i - 1]) + solve(i, k - 1, cuts, dp) +
                       solve(k + 1, j, cuts, dp);

            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        vector<vector<int>> dp(n, vector<int>(n, -1));

        sort(cuts.begin(), cuts.end());
        int c = cuts.size() - 2;
        return solve(1, c, cuts, dp);
    }
};

// Tabulation

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        int c = cuts.size() - 2;
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {
                int mini = 1e9;
                for (int k = i; k <= j; k++) {
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] +
                               dp[k + 1][j];

                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};
