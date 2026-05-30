// Tabulation

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

          int total = accumulate(nums.begin() , nums.end() , 0);
          int n = nums.size();

          if((total + target) % 2) return 0;
          if(abs(target) > total) return 0;

           int req = (total + target)/2;
           
           vector<vector<int>>dp(n , vector<int>(req+1 , 0));

           if(nums[0] == 0) dp[0][0] = 2;
           else dp[0][0] = 1;

           if(nums[0] != 0 && nums[0] <= req) dp[0][nums[0]] = 1;

           for(int i = 1 ; i < n ; i++){
              for(int sum = 0 ; sum <= req ; sum++){
                   
                   int notake = dp[i-1][sum];

                   int take = 0;

                   if(nums[i] <= sum) take = dp[i-1][sum - nums[i]];

                   dp[i][sum] = notake + take;
              }
           }

           return dp[n-1][req];

    }
};

// Space optimization

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

          int total = accumulate(nums.begin() , nums.end() , 0);
          int n = nums.size();

          if((total + target) % 2) return 0;
          if(abs(target) > total) return 0;

           int req = (total + target)/2;
           
            vector<int>dp(req+1 , 0);

           if(nums[0] == 0) dp[0] = 2;
           else dp[0] = 1;

           if(nums[0] != 0 && nums[0] <= req) dp[nums[0]] = 1;

           for(int i = 1 ; i < n ; i++){
              for(int sum = req ; sum >= 0 ; sum--){
                   
                   int notake = dp[sum];

                   int take = 0;

                   if(nums[i] <= sum) take = dp[sum - nums[i]];

                   dp[sum] = notake + take;
              }
           }

           return dp[req];

    }
};

// Memoization

class Solution {
public:
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = solve(ind - 1, target, nums, dp);

        int take = 0;
        if (nums[ind] <= target)
            take = solve(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total + target) % 2)
            return 0;
        if (abs(target) > total)
            return 0;
        int req = (total + target) / 2;

        vector<vector<int>> dp(n, vector<int>(req + 1, -1));
        return solve(n - 1, req, nums, dp);
    }
};
