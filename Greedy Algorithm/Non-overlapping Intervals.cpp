struct Data {
    int start;
    int end;
};

bool cmp(Data a, Data b) { return a.end < b.end; }

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        if (n == 0)
            return {};

        int cnt = 0;
        vector<Data>arr;

        for (auto& v : intervals) {
            arr.push_back({v[0], v[1]});
        }

        sort(arr.begin(), arr.end(), cmp);
        Data curr = arr[0];

        for (int i = 1; i < n; i++) {

            // overlaping
            if (curr.end > arr[i].start) {
                cnt++;
            } else {
                curr = arr[i];
            }
        }
        return cnt;
    }
};
