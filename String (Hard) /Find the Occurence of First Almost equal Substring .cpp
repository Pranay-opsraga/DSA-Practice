class Solution {
public:
    vector<int> solve(string& s) {
        int n = s.size();
        vector<int> Z(n, 0);
        int left = 0;
        int right = 0;

        for (int i = 1; i < n; i++) {
            if (i <= right) {
                Z[i] = min(right - i + 1, Z[i - left]);
            }

            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                Z[i]++;
            }

            if (i + Z[i] - 1 > right) {
                left = i;
                right = i + Z[i] - 1;
            }
        }
        return Z;
    }

    int minStartingIndex(string s, string pattern) {
        int n = s.size();
        int p = pattern.size();

        string nS = pattern + "$" + s;
        vector<int> ZP = solve(nS);

        string rs = s;
        reverse(rs.begin(), rs.end());

        string rp = pattern;
        reverse(rp.begin(), rp.end());

        string t = rp + "$" + rs;
        vector<int> ZS = solve(t);

        for (int i = 0; i + p <= n; i++) {
            int pref = ZP[p + 1 + i];

            int rev = n - (i + p);
            int suff = ZS[p + 1 + rev];

            if (pref + suff + 1 >= p)
                return i;
        }

        return -1;
    }
};
