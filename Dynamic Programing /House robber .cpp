class Solution {
public:
    int solve(vector<int>&nums , int n , vector<int>&dp , int ind){
         if( ind >= n) return 0;
         if(dp[ind] != -1) return dp[ind];

         int pick = nums[ind] + solve(nums , n , dp , ind+2);

         int notpick = solve(nums , n , dp , ind+1);
         int maxi = max(pick , notpick);
         return dp[ind] = maxi;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1 , -1);
        return solve(nums , n , dp , 0);
    }
};

// Space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;
        int prev1 = 0;

        for(int i = 0 ; i < n ; i++){
             int pick = nums[i] + prev2;
             int notpick = prev1;

             int curr = max(pick , notpick);
             prev2 = prev1;
             prev1 = curr;
        }
        return prev1;
    }
};
