#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
      int sle (vector<int>&nums){
        int largest = nums[0];
        int slargest = -1;
        for ( int i = 0 ; i < nums.size() ; i++){
            if ( largest < nums[i] ) {
              slargest = largest ;
            largest = nums[i];
           
            }
        if ( nums[i] < largest && nums[i] > slargest) slargest = nums[i];
        }
        return slargest;
      }
      
    int secondLargestElement(vector<int>& nums) {
       return sle(nums);
    }
};
int main (){
    int n ;
    cin>>n ;
    vector<int>arr(n);
     for ( int i =0 ; i < n ; i++){
        cin>>arr[i];
     }
     Solution obj;
   int result =  obj.secondLargestElement(arr);
   cout<<result;
return 0;
}