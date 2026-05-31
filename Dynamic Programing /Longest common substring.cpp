// Memoization

class Solution {
  public:
    
    int solve(int i , int j , string &s1, string &s2, vector<vector<int>>&dp , int &ans){
          if(i < 0 || j < 0) return 0;
          
          if(dp[i][j] != -1 ) return dp[i][j];
          int len = 0;
          if(s1[i] == s2[j]){
              len = 1 + solve(i-1, j-1 , s1 , s2 , dp , ans);
              ans = max(ans , len);
          } 
          
          solve(i-1 , j , s1 , s2 , dp , ans);
          solve(i , j-1 , s1 , s2 , dp , ans);
         
          
          return dp[i][j] = len;
          
    }
    
    int longCommSubstr(string& s1, string& s2) {
        
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        int ans = 0;
         solve(n-1 , m-1 , s1, s2 , dp , ans);
         return ans;
        
    }
        
};

// Tabulation

class Solution {
public:
    int longCommSubstr(string& s1, string& s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};

// space optimization

class Solution {
	public:
	
	int longCommSubstr(string& s1, string& s2) {
		
		int n = s1.size();
		int m = s2.size();
		
		vector<int>dp(m + 1, 0);
		int ans = 0;
		
		for (int i = 1; i <= n; i++) {
		    int prevdia = 0;
			for (int j = 1; j <= m; j++) {
			    int temp = dp[j];
				
				if (s1[i - 1] == s2[j - 1]) {
					dp[j] = 1 + prevdia;
					ans = max(ans , dp[j]);
				}
				else {
					dp[j] = 0 ;
				}
				prevdia = temp;
			}
		}
		
		return ans;
	}


};
