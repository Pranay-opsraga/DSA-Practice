class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev1 = 2;
        int prev2 = 1;
        for(int i = 3 ; i <= n ; i++){
              int curr = prev1 + prev2;
              prev2 = prev1;
              prev1 = curr;
        }
        return prev1;
    }
};

// Memoization

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Tabulation

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int prev1 = 2;
        int prev2 = 1;

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
