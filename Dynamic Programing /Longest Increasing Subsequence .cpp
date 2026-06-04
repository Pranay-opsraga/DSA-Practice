// Memoization

class Solution {
public:
    int solve(int ind , int prev , vector<int>& nums , vector<vector<int>>&dp){
           if(ind == nums.size()) return 0;

           if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

           int nottake = solve(ind+1 , prev , nums , dp);
           int take = 0;
           if(prev == -1 || nums[ind] > nums[prev] ) take = 1+solve(ind+1 , ind, nums , dp);

          return dp[ind][prev+1] = max(nottake , take);
    }
    int lengthOfLIS(vector<int>& nums) {
           int n = nums.size();

           vector<vector<int>>dp(n , vector<int>(n+1 , -1));
           return solve(0 , -1 , nums , dp);
    }
};

// Tabulation

class Solution {
public:
    
  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {

                int nottake = dp[ind+1][prev+1];
                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev])
                    take = 1 + dp[ind+1][ind+1];

                 dp[ind][prev + 1] = max(nottake, take);
            }
        }
        return dp[0][0];
    }
};

// Space optimization

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> ahead(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int prev = ind - 1; prev >= -1; prev--) {

                int nottake = ahead[prev + 1];

                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev])
                    take = 1 + ahead[ind + 1];

                curr[prev + 1] = max(take, nottake);
            }

            ahead = curr;
        }

        return ahead[0];
    }
};

// Binary Search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> temp;

        for (int i = 0; i < nums.size(); i++) {

            auto x = lower_bound(temp.begin(), temp.end(), nums[i]);

            if (x == temp.end())
                temp.push_back(nums[i]);
            else
                *x = nums[i];
        }

        return temp.size();
    }
};
