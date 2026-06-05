class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> cnt(n, 1);

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    if (lis[prev] + 1 > lis[i]) {
                        lis[i] = lis[prev] + 1;
                        cnt[i] = cnt[prev];
                    } else if (lis[prev] + 1 == lis[i])
                        cnt[i] += cnt[prev];
                }
            }
        }

        int ans = 0;
        int maxi = *max_element(lis.begin() , lis.end());

        for(int i = 0 ; i < n ; i++){
             if(lis[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};
