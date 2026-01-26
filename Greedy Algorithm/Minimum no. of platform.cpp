class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
           int n = Arrival.size();
            int m = Departure.size();
           sort(Arrival.begin(), Arrival.end());
           sort(Departure.begin() , Departure.end());

           int curr = 0;
           int ans = 0;
           int i = 0;
           int j = 0;

           while(i < n && j < m){
                 if(Arrival[i] <= Departure[j]){
                    curr++;
                    ans = max(ans , curr);
                    i++;

                 }else{
                     curr--;
                     j++;
                 }
           }
           return ans;
    }
};
