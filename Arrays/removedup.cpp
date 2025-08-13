#include<iostream>
#include<vector>
using namespace std;

 vector<int> removeDuplicates(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        
        for ( int j = 1 ; j < n ; j++){
            if ( nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
               
            }
        }
       nums.resize(i+1);
       return nums;
    }
    int main (){
    int n ;
    cin>>n ;
    vector<int>arr(n);
     for ( int i =0 ; i < n ; i++){
        cin>>arr[i];
     }
   vector<int>result =  removeDuplicates(arr);
   for ( int i = 0 ; i < result.size() ; i++){
    cout<<result[i]<<" ";
   }
return 0;
}