class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        //this is use when the value of the k is greater and the size of array is less 
        //it adjust the value of k
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
        
    }
};