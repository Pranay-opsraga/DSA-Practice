class Solution {
public:
    string generate(string s) {
        string ans = "";
        int cnt = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else {
                ans += to_string(cnt);
                ans += s[i-1];
                cnt = 1;
            }
        }

        ans += to_string(cnt);
        ans += s.back();
        return ans;
    }

    string countAndSay(int n) {
        string curr = "1";

        for (int i = 2; i <= n; i++) {
            curr = generate(curr);
        }
        return curr;
    }
};
