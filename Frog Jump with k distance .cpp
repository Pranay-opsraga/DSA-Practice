class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
            int n = heights.size();
            vector<int>dp(n+1 , -1);
            dp[0] = 0;

            for(int i = 1; i < n ; i++){
             int mini = INT_MAX;
            for(int j = 1 ; j <= k ; j++){
                if((i - j) >= 0)
                mini = min(abs(heights[i] - heights[i-j]) + dp[i-j] , mini);
             }
             dp[i] = mini;
            }
          return dp[n-1];
    }
};
