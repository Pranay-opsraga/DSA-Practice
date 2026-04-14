class Solution {
  public:
    int solve(int ind , int last , vector<vector<int>>&dp , vector<vector<int>>& mat ){
           if(ind == 0){
               int maxi = 0;
               for(int i = 0 ; i < 3 ; i++){
                    if(i != last){
                         maxi = max(mat[0][i] , maxi);
                    }
               }
               return maxi;
           }
           
           if(dp[ind][last] != -1) return dp[ind][last];
           
           int maxi = 0;
           for(int i = 0; i < 3 ; i++){
                if(i != last){
                    int points = mat[ind][i] + solve(ind - 1 , i , dp , mat);
                    maxi = max(maxi , points);
                }
           }
           return dp[ind][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
          int n = mat.size();
          vector<vector<int>>dp(n , vector<int>(4 , -1));
          return solve(n-1 , 3 , dp , mat);
        
    }
};

// Tabulation method

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<vector<int>>dp(n , vector<int>(4 , -1));
        
        dp[0][0] = max(mat[0][1] , mat[0][2]);
        dp[0][1] = max(mat[0][0] , mat[0][2]);
        dp[0][2] = max(mat[0][0] , mat[0][1]);
        dp[0][3] = max(max(mat[0][0] , mat[0][1]) , mat[0][2]);
        
        for(int i = 1 ; i < n ; i++){
             for(int last = 0; last < 4 ; last++){
                 int maxi = 0;
                 for(int task = 0 ; task < 3 ; task++){
                      if(task != last){
                          int points = mat[i][task] + dp[i-1][task];
                          maxi = max(maxi, points);
                      }
                 }
                 dp[i][last] = maxi;
             }
        }
        return dp[n-1][3];
        
    }
};

// Space Optimization 

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<int>prev(4 , 0);
        prev[0] = max(mat[0][1] , mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max({mat[0][0], mat[0][1], mat[0][2]});
        
        for(int i = 1 ; i < n ; i++){
            vector<int>temp(4, 0);
            for(int last = 0 ; last < 4 ; last++){
                 int maxi = 0;
                 for(int task = 0; task < 3 ; task++){
                       if(task != last){
                           int points = mat[i][task] + prev[task];
                           maxi = max(points , maxi);
                       }
                 }
                temp[last] = maxi; 
            }
            prev = temp;
        }
        return prev[3];
        
    }
};
