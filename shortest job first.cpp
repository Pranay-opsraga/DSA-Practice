class Solution {
  public:
    long long solve(vector<int>& bt) {
         int n = bt.size();
         long long total_waiting = 0;
         long long running_sum = 0;
         sort(bt.begin() , bt.end());

         for(int i = 0 ; i < n ; i++){
                total_waiting += running_sum;
                running_sum += bt[i];
         }
        return total_waiting/ n;
    }
};
