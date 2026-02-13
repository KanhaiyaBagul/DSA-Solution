class Solution {
public:
    int countElements(vector<int>& nums) {
        //find the max and min element first 
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        int count = 0;

        for(int num : nums){
            if(num > mn && num < mx){
                count++;
            }
        }
        return count;
        
    }
};