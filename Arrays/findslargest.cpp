class Solution {
public:
      int sle (vector<int>&nums){
        int largest = nums[0];
        int slargest = -1;
        for ( int i = 0 ; i < nums.size() ; i++){
            if ( largest < nums[i] ) largest = nums[i];
        
        if ( nums[i] < largest && nums[i] > slargest) slargest = nums[i];
        }
        return slargest;
      }
      
    int secondLargestElement(vector<int>& nums) {
       return sle(nums);
    }
};