class Solution {
public:
    vector<int> zFunction(string &s) {
        int n = s.size();
        vector<int> z(n, 0);

        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string t = s + "#" + rev;

        vector<int> z = zFunction(t);

        int len = 0;
        int n = t.size();

        for (int i = 0; i < n; i++) {
            if (i + z[i] == n) {
                len = max(len, z[i]);
            }
        }

        string rem = s.substr(len);
        reverse(rem.begin(), rem.end());

        return rem + s;
    }
};
