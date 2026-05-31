// Memoization

class Solution {
  public:
    int solve(int i , int j , string &s1, string &s2, vector<vector<int>>&dp){
          if(i < 0 || j < 0) return 0;
          
          if(dp[i][j] != -1 ) return dp[i][j];
          
          if(s1[i] == s2[j]) return 1 + solve(i-1, j-1 , s1 , s2 , dp);
          
          return dp[i][j] = max(solve(i-1 , j , s1 , s2 , dp) , solve(i , j-1 , s1 , s2 , dp));
          
    }
    int lcs(string &s1, string &s2) {
        
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        
        return solve(n-1 , m-1 , s1, s2 , dp);
        
    }
};

// Tabulation

class Solution {
public:
    int lcs(string &s1, string &s2) {
        
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

// space optimization

class Solution {
  public:

    int lcs(string &s1, string &s2) {
        
        int n = s1.size();
        int m = s2.size();
        vector<int>dp(m+1 , 0);
        
        for(int i = 1 ; i <= n ; i++){
             int prevdia = 0;
            for(int j = 1 ; j <= m ; j++){
                int temp = dp[j];
                if(s1[i-1] == s2[j-1]){
                    dp[j] = 1 + prevdia;
                } else dp[j] = max(dp[j] , dp[j-1]);
                
                prevdia = temp;
            }
        }
        return dp[m];
        
    }
};

