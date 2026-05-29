class Solution {
	public:
	int countPartitions(vector<int>& arr, int diff) {
		
		int n = arr.size();
		int total = accumulate(arr.begin(), arr.end(), 0);
		int target = (total + diff)/2;
		if (diff > total) return 0;
		if ((total + diff) % 2)
			return 0;
		
		vector<vector<int>> dp(n, vector<int>(target + 1, 0));
		
		if (arr[0] == 0)
			dp[0][0] = 2;
		else {
			dp[0][0] = 1;
			if (arr[0] <= total)
				dp[0][arr[0]] = 1;
		}
		
		for(int i = 1 ; i < n ; i++){
		   for(int sum = 0;  sum <= target ; sum++){
		        int nottake = dp[i-1][sum];
		        int take = 0;
		        if(arr[i] <= sum)
		        take = dp[i-1][sum-arr[i]];
		        
		        dp[i][sum] = nottake+ take;
		   }
		}
		return dp[n-1][target];
		
	}
};

// space optimization

class Solution {
	public:
	int countPartitions(vector<int>& arr, int diff) {
		
		int n = arr.size();
		int total = accumulate(arr.begin(), arr.end(), 0);
		int target = (total + diff)/2;
		if (diff > total) return 0;
		if ((total + diff) % 2)
			return 0;
		
		 vector<int>prev(target + 1, 0);
		 vector<int>curr(target + 1, 0);
		
		if (arr[0] == 0)
			prev[0] = 2;
		else {
			prev[0] = 1;
			if (arr[0] <= total)
				prev[arr[0]] = 1;
		}
		
		for(int i = 1 ; i < n ; i++){
		   for(int sum = 0;  sum <= target ; sum++){
		        int nottake = prev[sum];
		        int take = 0;
		        if(arr[i] <= sum)
		        take = prev[sum-arr[i]];
		        
		        curr[sum] = nottake+ take;
		   }
		   prev = curr;
		}
		return curr[target];
		
	}
};
