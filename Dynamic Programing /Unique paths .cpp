class Solution {
public:
    int solve(int i , int j ,  vector<vector<int>>&dp , int n , int m){
         if(i == n-1 && j == m-1 ) return 1;
         if( i >= n || j >= m) return 0;

         if(dp[i][j] != -1) return dp[i][j];

         int right = solve(i , j+1 , dp , n , m);
         int down = solve(i+1 , j , dp , n , m);

         return dp[i][j] = right + down;

    }
    int uniquePaths(int m, int n) {
       
        vector<vector<int>>dp(m , vector<int>(n , -1));
         return solve(0  , 0, dp , m , n);
        
    }
};

// Tabulation 

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Space Optimization 

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev( n ,1);

        for(int i = 1 ; i < m ; i++){
            vector<int>curr( n , 1);
            for(int j = 1 ; j < n ; j++){
                curr[j] = curr[j-1] + prev[j];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
