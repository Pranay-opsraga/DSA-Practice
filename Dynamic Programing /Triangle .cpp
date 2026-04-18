class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& dp,
              vector<vector<int>>& triangle) {

        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int total = triangle[i][j] + min(solve(i + 1, j, n, dp, triangle),
                                         solve(i + 1, j + 1, n, dp, triangle));

        return dp[i][j] = total;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
      

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return solve(0, 0, n, dp, triangle);
    }
};
// Tabulation 

class Solution {
public:
  
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
      
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
      

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <= i ; j++){
                 
                 int up = INT_MAX;
                 int dia = INT_MAX;
                 if(j < i) up = dp[i-1][j];
                 if(j > 0)  dia = dp[i-1][j-1];

                 int total = min(up , dia);
                 dp[i][j] = triangle[i][j] + total;
            }
        }
        int ans = INT_MAX;
        for(int j = 0 ; j < n ; j++){
             ans = min(ans , dp[n-1][j]);
        }
        return ans;
        
    }
};

// Space optimization

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp = triangle[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j <= i ; j++){
                dp[j] = triangle[i][j] + min(dp[j] , dp[j+1]);
            }
        }
        return dp[0];
    }
};
