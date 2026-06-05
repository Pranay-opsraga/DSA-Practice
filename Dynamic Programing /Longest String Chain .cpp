class Solution {
public:
    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1)
            return false;

        int curr = 0;
        int prev = 0;

        while (curr < s1.size()) {
            if (prev < s2.size() && s1[curr] == s2[prev]) {
                curr++;
                prev++;
            } else {
                curr++;
            }
        }
        return (prev == s2.size());
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string& s1, string& s2) { return s1.size() < s2.size(); });

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {

                if (check(words[i], words[prev]) && dp[prev] + 1 > dp[i]) {

                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
