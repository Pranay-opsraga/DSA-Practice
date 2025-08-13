class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n; // handle k >= n

        // Step 1: Reverse first n-k elements
        reverse(nums.begin(), nums.begin() + (k));
        // Step 2: Reverse last k elements
        reverse(nums.begin() + (k), nums.end());
        // Step 3: Reverse entire array
        reverse(nums.begin(), nums.end());
    }
};
