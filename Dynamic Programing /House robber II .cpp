class Solution {
public:
     int solve(vector<int>&nums , int start , int end ){
            
             
             int n = end - start + 1;
             vector<int>dp(n);
             

              dp[0] = nums[start];
              if(n == 1)
            return dp[0];
              dp[1] = max(nums[start] , nums[start+1]);
              

             for(int i = 2 ; i < n ; i++){
                   int pick = dp[i-2] + nums[start+i];
                   int notpick = dp[i-1];

                   dp[i] = max(pick, notpick);
             }
             return dp[n-1];
     }
 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solve(nums , 0 , n-2  ) , solve(nums , 1 , n-1  ));

    }
};

//Space optimiation

// Memoization

class Solution {
public:

    int solve(vector<int>& nums,
              int start,
              int end,
              int ind,
              vector<int>& dp) {

        if(ind > end)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int pick =
            nums[ind] + solve(nums, start, end, ind+2, dp);

        int notpick =
            solve(nums, start, end, ind+1, dp);

        return dp[ind] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 =
            solve(nums, 0, n-2, 0, dp1);

        int case2 =
            solve(nums, 1, n-1, 1, dp2);

        return max(case1, case2);
    }
};
