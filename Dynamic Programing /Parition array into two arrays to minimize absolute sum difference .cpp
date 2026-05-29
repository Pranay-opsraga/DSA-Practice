// Memoization

class Solution {
public:
    int total;

    int solve(int ind, int sum, vector<int>& arr,
              vector<vector<int>>& dp) {

        if (ind == arr.size()) {
            int other = total - sum;
            return abs(sum - other);
        }

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int take = solve(ind + 1, sum + arr[ind], arr, dp);
        int notTake = solve(ind + 1, sum, arr, dp);

        return dp[ind][sum] = min(take, notTake);
    }

    int minDifference(vector<int>& arr, int n) {

        total = accumulate(arr.begin(), arr.end(), 0);

        vector<vector<int>> dp(n, vector<int>(total + 1, -1));

        return solve(0, 0, arr, dp);
    }
};

// Tabulation

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int total = accumulate(arr.begin() , arr.end() , 0);
        vector<vector<bool>>dp(n , vector<bool>(total+1 , false));
        
        for(int i = 0 ; i < n ; i++){
             dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;
        
        for(int i = 1 ; i < n ; i++){
            for(int target = 1 ; target <= total ; target++){
                  
                  bool nottake = dp[i-1][target];
                  bool take = false;
                  if(arr[i] <= target) take = dp[i-1][target-arr[i]];
                  
                  dp[i][target] = nottake | take;
            }
        }
        int ans = INT_MAX;
        for(int s1 = 0 ; s1 <= total/2 ; s1++){
             if(dp[n-1][s1]){
                 ans = min(ans , abs((total - s1) - s1));
             }
        }
        
        return ans;
    }
};


// Space optimization

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int total = accumulate(arr.begin() , arr.end() , 0);
        vector<bool>curr(total+1 , false);
        vector<bool>prev(total+1 , false);
        
        
            prev[0] = curr[0] = true;
        
            prev[arr[0]] = true;
        
        for(int i = 1 ; i < n ; i++){
            for(int target = 1 ; target <= total ; target++){
                  
                  bool nottake = prev[target];
                  bool take = false;
                  if(arr[i] <= target) take = prev[target-arr[i]];
                  
                  curr[target] = nottake | take;
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(int s1 = 0 ; s1 <= total/2 ; s1++){
             if(prev[s1]){
                 ans = min(ans , abs((total - s1) - s1));
             }
        }
        
        return ans;
    }
};


