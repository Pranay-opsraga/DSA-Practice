class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> validIntervals;

        for (int ch = 0; ch < 26; ch++) {
            if (first[ch] == -1)
                continue;

            int l = first[ch];
            int r = last[ch];
            bool valid = true;

            for (int i = l; i < r; i++) {
                int ch2 = s[i] - 'a';

                if (first[ch2] < l) {
                    valid = false;
                    break;
                }

                r = max(last[ch2], r);
            }

            if (valid) {
                validIntervals.push_back({l, r});
            }
        }

        sort(validIntervals.begin(), validIntervals.end(),
             [](auto& a, auto& b) { return a.second < b.second ;});

            int prevend = -1;
        vector<string>res;
        for (auto it : validIntervals) {
            if (it.first > prevend) {
                res.push_back(s.substr(it.first, it.second - it.first + 1));
                prevend = it.second;
            }
        }

        return res;
    }
};
