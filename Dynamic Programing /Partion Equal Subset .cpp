// Tabulation

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total & 1)
            return false;

        int sum = total / 2;

        vector<vector<bool>> dp(200, vector<bool>(10000, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum ; target++) {
                bool nottake = dp[i - 1][target];

                bool take = false;

                if (target >= nums[i])
                    take = dp[i - 1][target - nums[i]];

                dp[i][target] = (nottake == true || take == true);
            }
        }
        return dp[n - 1][sum];
    }
};

// Space optimization

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total & 1)
            return false;

        int sum = total / 2;

        vector<bool> curr(10000, false);
        vector<bool> prev(10000, false);

        prev[0] = true;

        prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool nottake = prev[target];

                bool take = false;

                if (target >= nums[i])
                    take = prev[target - nums[i]];

                curr[target] = (nottake == true || take == true);
            }
            prev = curr;
        }
        return curr[sum];
    }
};


