class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int>dp(n + 1, 0);
        string rev = s;
        reverse(rev.begin(), rev.end());

        for (int i = 1; i <= n; i++) {
            int prevdia = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (s[i-1] == rev[j-1])
                    dp[j] = 1 + prevdia;

                else {
                    dp[j] = max(dp[j] , dp[j - 1]);
                }
             prevdia = temp;
            }
        }
        return dp[n];
    }
    int minInsertions(string s) {
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    }
};
