class Solution {
public:
    int solve(string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += solve(s, i, i);
            ans += solve(s, i, i + 1);
        }
        return ans;
    }
};

// Dp Approach

class Solution {
public:
    bool solve(int i , int j , vector<vector<int>>&dp , string &s){
         if( i >= j) return true;

         if(dp[i][j] != -1) return dp[i][j];

         if(s[i] != s[j]) return dp[i][j] = false;

         return dp[i][j] = solve(i+1 , j-1 , dp , s);
    }
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>>dp(n , vector<int>(n , -1));
        int cnt= 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                 if(solve(i , j , dp , s)){
                    cnt++;
                 }
            }
        }
        return cnt;
    }
};

