class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
           int n = intervals.size();
           if (n == 0) return {};

           vector<vector<int>>res;
           sort(intervals.begin(), intervals.end());
           vector<int>curr = intervals[0];
           for(int i = 1 ; i < n ; i++){
                  
                  if(curr[1] >= intervals[i][0]){
                        curr[1] = max(curr[1] , intervals[i][1]);
                  } else {
                       res.push_back(curr);
                       curr = intervals[i];
                  }
           }
           res.push_back(curr);
           return res;
    }
};
