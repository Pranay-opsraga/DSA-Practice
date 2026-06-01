// Memoization

class Solution {
public:
   int solve(int i , int j ,string s, string t , vector<vector<int>>&dp ){
           if( j < 0) return 1;
           if(i < 0) return 0;

           if(dp[i][j] != -1) return dp[i][j];
           
           int nottake = solve(i-1 , j , s, t , dp);
           int take = 0;
           if(s[i] == t[j]){
               take = solve(i-1 , j-1 , s, t , dp);
               nottake = solve(i-1 , j , s, t , dp);
           }

           else {
               nottake = solve(i-1 , j , s, t , dp);
           }
           return dp[i][j] = take + nottake;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
          vector<vector<int>>dp(n , vector<int>(m , -1));
          return solve(n-1 , m-1 , s , t , dp);
    }
};

// tabulation

class Solution {
public:
    using ull = unsigned long long;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<ull>> dp(n + 1, vector<ull>(m + 1, 0));

        dp[0][0] = 1;
        for(int i = 1 ; i <= n ; i++){
             dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                ull nottake = dp[i-1][j];
                ull take = 0;
                if (s[i-1] == t[j-1]) {
                    take = dp[i-1][j-1];
                }
              dp[i][j] = take + nottake;
            }
        }
        return dp[n][m];
    }
};

// space optimization

class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<unsigned long long> dp(m + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            for (int j = m; j >= 1; j--) {

                unsigned long long notTake = dp[j];
                unsigned long long take = 0;

                if (s[i - 1] == t[j - 1]) {
                    take = dp[j - 1];
                }

                dp[j] = take + notTake;
            }
        }

        return dp[m];
    }
};
