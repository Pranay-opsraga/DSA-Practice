class Solution {
public:
     // bool canreach(vector<int>& nums, int i, int n) {
    //     if (i == n - 1)
    //         return true;
    //     if (i >= n || nums[i] == 0)
    //         return false;

    //     for (int step = 1; step <= nums[i]; step++) {
    //         if (canreach(nums, i + step, n))
    //             return true;
    //     }
    //     return false;
    // }
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int reachable = 0;
        for(int i = 0 ; i < n ; i++){
             if(i > reachable) return false;
             reachable = max(reachable , i+nums[i]);
             if(reachable >= n-1) return true;
        }
        return true;
    }
};
