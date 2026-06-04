class Solution {
	public:
	vector<int> getLIS(vector<int>& arr) {
		
		int n = arr.size();
		vector<int>dp(n, 1);
		vector<int>unionSet(n);
		
		int maxi = 1;
		int lastIndex = 0;
		
		for (int i = 0 ; i < n ; i++) {
			unionSet[i] = i;
			
			for (int prev = 0 ; prev < i ; prev++) {
				if (arr[prev] < arr[i] && dp[prev]+1 > dp[i]) {
					dp[i] = dp[prev]+1;
					unionSet[i] = prev;
				}
			}
			
			if(maxi < dp[i]){
			    lastIndex = i;
			    maxi = dp[i];
			}
		}
		
		vector<int>lis;
		
		while(unionSet[lastIndex] != lastIndex){
		       lis.push_back(arr[lastIndex]);
		       lastIndex = unionSet[lastIndex];
		}
		lis.push_back(arr[lastIndex]);
		
		reverse(lis.begin() , lis.end());
		return lis;
		
	}
};
