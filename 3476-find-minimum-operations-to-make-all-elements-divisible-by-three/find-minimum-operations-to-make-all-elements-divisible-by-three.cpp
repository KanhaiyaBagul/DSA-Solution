class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int num : nums){
            count += min(num % 3 , 3 - (num % 3));
        }
        return count;
        
    }
};