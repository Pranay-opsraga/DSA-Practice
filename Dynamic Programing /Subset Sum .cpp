// Memoization

class Solution {
  public:
    bool solve(int ind , int target , vector<int>&arr , vector<vector<int>>&dp ){
        
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool nottake = solve(ind-1 , target , arr , dp );
        
        bool take = false;
        
        if(target >= arr[ind]) take = solve(ind-1 , target-arr[ind] , arr ,dp);
        
        return dp[ind][target] = (nottake == true || take == true);
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(200 , vector<int>(10000 , -1));
        return solve(n-1 , sum , arr , dp);
        
    }
};

// Tabulation

class Solution {
	public:
	bool isSubsetSum(vector<int>& arr, int sum) {
		int n = arr.size();
		vector<vector<bool>> dp(200, vector<bool>(10000, false));
		
		for (int i = 0 ; i < n ; i++) {
			dp[i][0] = true;
		}
		
		dp[0][arr[0]] = true;
		
		for (int i = 1 ; i < n ; i++) {
			for (int target = 1 ; target <= sum ; target++) {
				bool nottake = dp[i-1][target];
				
				bool take = false;
				
				if (target >= arr[i])
					take = dp[i-1][target-arr[i]];
				
				 dp[i][target] = (nottake == true || take == true);
			}
		}
		return dp[n-1][sum];
		
	}
};

// Space optimization

class Solution {
	public:
	bool isSubsetSum(vector<int>& arr, int sum) {
		int n = arr.size();
		 vector<bool>curr(10000, false);
		 vector<bool>prev(10000 , false);
		
		
	    prev[0] = true;
		prev[arr[0]] = true;
		
		for (int i = 1 ; i < n ; i++) {
		    
			for (int target = 1 ; target <= sum ; target++) {
				bool nottake = prev[target];
				
				bool take = false;
				
				if (target >= arr[i])
					take = prev[target-arr[i]];
				
				 curr[target] = (nottake == true || take == true);
			}
			prev = curr;
		}
		return curr[sum];
		
	}
};

