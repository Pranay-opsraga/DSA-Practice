// Memoization 

class Solution {
public:
    int solve(int ind , int target , vector<int>& coins , vector<vector<int>>&dp ){
                
                if(target == 0) return 1;
               
               if(ind == 0){
                  return ((target % coins[0]) == 0);
               }

               if(dp[ind][target] != -1){
                    return dp[ind][target];
               }

               int nottake = solve(ind-1 , target , coins , dp);

               int take = 0;
               if(coins[ind] <= target){
                   take = solve(ind , target-coins[ind] , coins , dp);
               }

               return dp[ind][target] = nottake + take;
       }
    int change(int amount, vector<int>& coins) {
         
         int n = coins.size();

         vector<vector<int>>dp(n , vector<int>(amount+1 , -1));
         return solve(n-1 , amount , coins , dp);
    }
};

// Tabulation

using ull = unsigned long long;

class Solution {
public:
    ull change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<ull>> dp(n, vector<ull>(amount + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) {
                dp[0][target] = 1;
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= amount; target++) {

                ull nottake = dp[ind - 1][target];

                ull take = 0;
                if (coins[ind] <= target) {
                    take = dp[ind][target - coins[ind]];
                }

                dp[ind][target] = nottake + take;
            }
        }

        return dp[n - 1][amount];
    }
};
// Space optimization

using ull = unsigned long long;

class Solution {
public:
    ull change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<ull>dp(amount + 1, 0);

      
            dp[0] = 1;


        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) {
                dp[target] = 1;
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= amount; target++) {

                ull nottake = dp[target];

                ull take = 0;
                if (coins[ind] <= target) {
                    take = dp[target - coins[ind]];
                }

                dp[target] = nottake + take;
            }
        }

        return dp[amount];
    }
};
