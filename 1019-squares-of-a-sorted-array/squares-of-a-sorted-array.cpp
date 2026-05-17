class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector<int>result(n);

        int i = n - 1;
        while(low <= high){
            if(abs(nums[low]) > abs(nums[high])){
                int sqr = pow(nums[low],2);
                result[i] = sqr;
                low++;
            }else{
                int sqr = pow(nums[high],2);
                result[i] = sqr;
                high--;
            }
            i--;
        }
        return result;
        
    }
};