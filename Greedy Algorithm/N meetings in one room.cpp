struct data {
      int start;
      int end;
};

bool cmp (data a , data b){
      return a.end < b.end;
}
class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
            int cnt = 0;
            int freetime = -1;
            int n = start.size();
            vector<data>arr;

            for(int i = 0 ; i < start.size() ; i++){
                   arr.push_back({start[i],end[i]});
            }
            sort(arr.begin(),arr.end() , cmp);
        
            for(int i = 0 ; i < n ; i++){
                if(arr[i].start > freetime) {
                    cnt++;
                    freetime = arr[i].end;
                }

            }
            return cnt;
    }
};
