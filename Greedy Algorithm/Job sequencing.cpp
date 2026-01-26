struct Data {
    int id;
    int deadline;
    int profit;
};

bool cmp(Data a, Data b) {
    return a.profit > b.profit;
}

class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        int n = Jobs.size();

        vector<Data> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({Jobs[i][0], Jobs[i][1], Jobs[i][2]});
        }

        sort(arr.begin(), arr.end(), cmp); 

        int maxDeadline = 0;
           for (int i = 0; i < n; i++) {
          maxDeadline = max(maxDeadline, arr[i].deadline);
             }

          set<int> slot;
           for (int i = 1; i <= maxDeadline; i++) {
                  slot.insert(i);
             }

        int cnt = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
                  auto it = slot.upper_bound(arr[i].deadline);

                  if(it != slot.begin()){
                       it--;
                       cnt++;
                       totalProfit += arr[i].profit;
                       slot.erase(it);
                  }
            }
            return {cnt, totalProfit};
        }  
    };
