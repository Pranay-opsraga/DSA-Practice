// Tabulation

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(word1 == word2) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                }
            }
        }
        int lcs = dp[n][m];
        return n+m - 2* lcs;
    }
};

// space optimization

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>dp(m+1 , 0);
        
        for(int i = 1 ; i <= n ; i++){
             int prevdia = 0;
            for(int j = 1 ; j <= m ; j++){
                int temp = dp[j];
                if(word1[i-1] == word2[j-1]){
                    dp[j] = 1 + prevdia;
                } else dp[j] = max(dp[j] , dp[j-1]);
                
                prevdia = temp;
            }
        }
         return n+m - 2* dp[m];
        
    }
};
