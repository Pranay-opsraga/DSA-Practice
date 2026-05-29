class Solution {
	public:

	int solve(int ind, int sum, int target, vector<int>&arr, vector<vector<int>>&dp , int n) {
		
		if (ind == n) {
			return (sum == target);
		}
		
		if(dp[ind][sum] != -1) return dp[ind][sum];
		int take = 0;
		if (sum + arr[ind] <= target)
			take = solve(ind + 1, sum + arr[ind], target, arr, dp ,  n);
		int nottake = solve(ind + 1, sum, target, arr, dp ,  n);
		
		return dp[ind][sum] = nottake + take;
	}
	int perfectSum(vector<int>& arr, int target) {
		
		int n = arr.size();
		vector<vector<int>>dp(n, vector<int>(target + 1, -1));
		return solve(0, 0, target ,  arr, dp ,  n);
		
	}
};

// Tabulation

class Solution {
	public:
	int perfectSum(vector<int>& arr, int target) {
		
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(target + 1, 0));
		
		if (arr[0] == 0)
			dp[0][0] = 2;
		else {
			dp[0][0] = 1;
			if (arr[0] <= target)
				dp[0][arr[0]] = 1;
		}
		
		for (int i = 1 ; i < n ; i++) {
			for (int sum = 0 ; sum <= target ; sum++) {
				
				int nottake = dp[i - 1][sum];
				
				int take = 0;
				if (arr[i] <= sum)
					take = dp[i - 1][sum - arr[i]];
				
				dp[i][sum] = nottake + take;
				
			}
		}
		return dp[n - 1][target];
		
	}
};

// Space optimization

class Solution {
	public:
	int perfectSum(vector<int>& arr, int target) {
		
		int n = arr.size();
		vector<int>prev(target + 1, 0);
		vector<int>curr(target + 1, 0);
		
		if (arr[0] == 0)
			prev[0] = 2;
		else {
			prev[0] = 1;
			if (arr[0] <= target)
				prev[arr[0]] = 1;
		}
		
		for (int i = 1 ; i < n ; i++) {
			for (int sum = 0 ; sum <= target ; sum++) {
				
				int nottake = prev[sum];
				
				int take = 0;
				if (arr[i] <= sum)
					take = prev[sum - arr[i]];
				
				curr[sum] = nottake + take;
				
			}
			prev = curr;
		}
		return prev[target];
		
	}
};
