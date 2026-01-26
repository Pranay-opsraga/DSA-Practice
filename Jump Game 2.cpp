class Solution {
public:
    int jump(vector<int>& nums) {
          int n = nums.size();
          int maxReach = 0;
          int jumps = 0;
          int currend = 0;
          if(n <= 1) return 0;
          for(int i = 0 ; i < n-1 ; i++){
                maxReach = max(i+nums[i] , maxReach);

                if(i == currend){
                    jumps++;
                    currend = maxReach;
                }
          }
          return jumps;
    }
};
