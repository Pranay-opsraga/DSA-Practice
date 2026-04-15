class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp) {
        if (obstacleGrid[n - 1][m - 1])
            return 0;
        if (i == n - 1 && j == m - 1)
            return 1;
        if (i >= n || j >= m)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j + 1, n, m, obstacleGrid, dp);
        int down = solve(i + 1, j, n, m, obstacleGrid, dp);

        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, obstacleGrid, dp);
    }
};

// Tabulation 

class Solution {
public:
   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;
        
        for(int i = 1 ; i < n ; i++){
             if(obstacleGrid[i][0] == 0) dp[i][0] = dp[i-1][0];
            
        }
        for(int j = 1 ; j < m ; j++){
             if(obstacleGrid[0][j] == 0) dp[0][j] = dp[0][j-1];
        }

        for(int i = 1; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j]+ dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

// Sapce Optimization

class Solution {
public:
   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<int>dp(m, 0);
        dp[0] = 1;
        
        
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else if(j > 0) dp[j] += dp[j-1];
            }
        }
        return dp[m-1];
    }
};
