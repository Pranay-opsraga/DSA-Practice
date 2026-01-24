struct Item {
     long long value;
     long long weight;
};

bool cmp (Item a , Item b){
     double r1 = (double)a.value / a.weight;
     double r2 = (double)b.value / b.weight;
     return r1 > r2;
}

class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
           int n = val.size();
           vector<Item>items;

           for(int i = 0 ; i < n ; i++){
                  items.push_back({val[i] , wt[i]});
           }
           sort(items.begin(), items.end() , cmp);
           
           double totalvalue = 0;

           for(int i = 0 ; i < n ; i++){
                 if(items[i].weight <= capacity){
                     totalvalue += items[i].value;
                     capacity -= items[i].weight;
                 }else {
                     totalvalue += (double)items[i].value * capacity/ items[i].weight;
                     break;
                 }
           }
           return totalvalue;

    }
};
