class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        //for a valid triagle A + B > C we just have to check this condition 
        sort(nums.begin(),nums.end());

        for(int i = 2; i < n; i++){
            int left = 0;
            int right = i - 1;
            while(left < right){
                if(nums[left] + nums[right] > nums[i]){
                    result += right - left;
                    right--;
                }else{
                    left ++;
                }
            }
        }
        return result;
        
    }
};