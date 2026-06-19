class Solution {
public:
    int solve(string& ns) {
        int n = ns.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (ns[i] == ns[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1];
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string ns = s + "#" + rev;

        int lp = solve(ns);

        string rem = s.substr(lp);
        reverse(rem.begin(), rem.end());

        return rem + s;
    }
};
