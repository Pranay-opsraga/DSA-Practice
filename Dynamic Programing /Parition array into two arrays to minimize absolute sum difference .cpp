// Memoization

class Solution {
public:
    int total;

    int solve(int ind, int sum, vector<int>& arr,
              vector<vector<int>>& dp) {

        if (ind == arr.size()) {
            int other = total - sum;
            return abs(sum - other);
        }

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int take = solve(ind + 1, sum + arr[ind], arr, dp);
        int notTake = solve(ind + 1, sum, arr, dp);

        return dp[ind][sum] = min(take, notTake);
    }

    int minDifference(vector<int>& arr, int n) {

        total = accumulate(arr.begin(), arr.end(), 0);

        vector<vector<int>> dp(n, vector<int>(total + 1, -1));

        return solve(0, 0, arr, dp);
    }
};

// Tabulation

