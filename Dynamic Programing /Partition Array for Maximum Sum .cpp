// Memoization

class Solution {
public:
    int solve(int i, int n, vector<int>& arr, int k, vector<int>& dp) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int maxAns = 0;
        int maxi = INT_MIN;
        int len = 0;

        for (int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + solve(j + 1, n, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, n, arr, k, dp);
    }
};

// Tabulation

class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int maxAns = 0;
            int maxi = INT_MIN;
            int len = 0;

            for (int j = i; j < min(n, i + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len * maxi) + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};
