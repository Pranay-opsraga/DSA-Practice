// Memoization

class Solution {
public:
    int solve(int i , int j , string& s , vector<vector<int>>&dp){
          
          if(i > j) return 0;
          if(i == j) return 1;

          if(dp[i][j] != -1) return dp[i][j];

          if(s[i] == s[j]) return 2 + solve(i+1 , j-1 , s , dp);

         return dp[i][j] =  max( solve(i , j-1 , s , dp) ,
          solve(i+1 , j , s , dp));

    }
    int longestPalindromeSubseq(string s) {
         int n = s.size();
         vector<vector<int>>dp(n , vector<int>(n , -1));
        return solve(0 , n-1 , s , dp);
    }
};

// Tabulation

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        string rev = s;
        reverse(rev.begin(), rev.end());

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i-1] == rev[j-1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};

// space optimization

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int>dp(n + 1, 0);
        string rev = s;
        reverse(rev.begin(), rev.end());

        for (int i = 1; i <= n; i++) {
            int prevdia = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (s[i-1] == rev[j-1])
                    dp[j] = 1 + prevdia;

                else {
                    dp[j] = max(dp[j] , dp[j - 1]);
                }
             prevdia = temp;
            }
        }
        return dp[n];
    }
};
