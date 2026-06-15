// Rabin - Karp Algo


class Solution {
public:
    static const long long MOD = 1e9;
    static const long long P = 31;

    bool solve(string& text, string& pat) {
        int n = text.size();
        int m = pat.size();

        vector<long long> power(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * P) % MOD;
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            long long  val = text[i] - 'a' + 1;
            pref[i + 1] = (pref[i] + val * power[i]) % MOD;
        }

        long long patternHash = 0;

        for (int i = 0; i < m; i++) {
            long long val = pat[i] - 'a' + 1;

            patternHash = (patternHash + val * power[i]) % MOD;
        }

        for (int l = 0; l + m - 1 < n; l++) {
            int r = l + m - 1;

            long long curr = (pref[r + 1] - pref[l] + MOD) % MOD;
            long long target = (patternHash * power[l]) % MOD;

            if (curr == target) {

                bool same = true;

                for (int k = 0; k < m; k++) {
                    if (text[l + k] != pat[k]) {
                        same = false;
                        break;
                    }
                }

                if (same)
                    return true;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {

        string s = "";
        int cnt = 0;
        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }

        if (solve(s, b)) {
            return cnt;
        }

        s += a;

        if (solve(s, b)) {
            return cnt + 1;
        }

        return -1;
    }
};

// Brute - force 

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        int cnt = 0;

        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }

        if (s.find(b) != string::npos)
            return cnt;

        s += a;

        if (s.find(b) != string::npos)
            return cnt + 1;

        return -1;
    }
};
