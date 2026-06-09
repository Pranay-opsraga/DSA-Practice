// Memoization

class Solution {
public:
    bool isPalindrome(string& temp){
        int l = 0;
        int r = temp.size()-1;
          while(l < r){
              if(temp[l] != temp[r]) return false;
              l++;
              r--;
          }
          return true;
    }
    int solve(int i , int n , string& s , vector<int>&dp ){
          if(i == n) return 0;

          if(dp[i] != -1) return dp[i];
          string temp = "";
          int mini = INT_MAX;
          for(int j = i ; j < n ; j++){
              temp += s[j];
              if(isPalindrome(temp)){
                 int cost = 1 + solve(j+1 , n , s , dp);
                 mini = min(mini , cost);
              }
          } 
          return dp[i] = mini; 
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return solve(0 , n , s, dp) - 1;
    }
};

// Tabulation

class Solution {
public:
    bool isPalindrome(string& temp) {
        int l = 0;
        int r = temp.size() - 1;
        while (l < r) {
            if (temp[l] != temp[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);

        for (int i = n - 1; i >= 0; i--) {
            string temp = "";
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                temp += s[j];
                if (isPalindrome(temp)) {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0];
    }
};
