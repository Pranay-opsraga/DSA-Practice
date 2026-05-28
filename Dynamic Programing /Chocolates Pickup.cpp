// Memoization

class Solution {
  public:
    int solve(int i , int j1 , int j2 , int n , int m , vector<vector<vector<int>>>&dp , vector<vector<int>>& grid){
        
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
        
        if(i == n-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = 0;
        
        for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
             for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                 if(j1 == j2) maxi = max(grid[i][j1] + solve(i+1 , j1+dj1 , j2+dj2 , n , m , dp , grid ) , maxi);
                 else maxi = max(grid[i][j1] + grid[i][j2] + solve(i+1 , j1+dj1 , j2+dj2 , n , m , dp , grid ) , maxi);
             }
        }
        return dp[i][j1][j2] = maxi;
    }
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(m , -1)));
        return solve(0 , 0 , m-1 , n , m ,  dp , grid);
        
    }
};

// Space optimization

class Solution {
	public:
	int maxChocolate(vector<vector<int>> & grid) {
		
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>>front(m ,vector<int>(m , 0));
		vector<vector<int>>curr(m ,vector<int>(m , 0));
		
		for (int j1 = 0 ; j1 < m ; j1++) {
			for (int j2 = 0 ; j2 < m ; j2++) {
				if (j1 == j2)
					front[j1][j2] = grid[n-1][j1];
				else
					front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
			}
		}
		
		for (int i = n - 2 ; i >= 0 ; i--) {
			for (int j1 = 0 ; j1 < m ; j1++) {
				for (int j2 = 0 ; j2 < m ; j2++) {
					int maxi = 0;
					for (int dj1 = -1 ; dj1 <= 1 ; dj1++) {
						for (int dj2 = -1 ; dj2 <= 1 ; dj2++) {
						    int val = 0;
							if (j1 == j2) val = grid[i][j1]; 
							else
								val = grid[i][j1] + grid[i][j2];
								
							if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m )
							val += front[j1+dj1][j2+dj2];
							
							else val = -1e8;
							maxi = max(maxi , val);
						}
						
					}
					curr[j1][j2] = maxi;
				}
			}
			front = curr;
			
		}
		return front[0][m-1];
		
	}
};


// Tabulation

class Solution {
	public:
	int maxChocolate(vector<vector<int>> & grid) {
		
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<vector<int>> >dp(n, vector<vector<int>> (m, vector<int>(m , 0)));
		
		for (int j1 = 0 ; j1 < m ; j1++) {
			for (int j2 = 0 ; j2 < m ; j2++) {
				if (j1 == j2)
					dp[n - 1][j1][j2] = grid[n-1][j1];
				else
					dp[n - 1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
			}
		}
		
		for (int i = n - 2 ; i >= 0 ; i--) {
			for (int j1 = 0 ; j1 < m ; j1++) {
				for (int j2 = 0 ; j2 < m ; j2++) {
					int maxi = 0;
					for (int dj1 = -1 ; dj1 <= 1 ; dj1++) {
						for (int dj2 = -1 ; dj2 <= 1 ; dj2++) {
						    int val = 0;
							if (j1 == j2) val = grid[i][j1]; 
							else
								val = grid[i][j1] + grid[i][j2];
								
							if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m )
							val += dp[i+1][j1+dj1][j2+dj2];
							
							else val = -1e8;
							maxi = max(maxi , val);
						}
						
					}
					dp[i][j1][j2] = maxi;
				}
			}
			
		}
		return dp[0][0][m-1];
		
	}
};

