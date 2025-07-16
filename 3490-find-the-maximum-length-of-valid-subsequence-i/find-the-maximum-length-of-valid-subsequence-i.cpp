class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int evenCount = 0;
        int oddCount = 0;
        int alternat = 0;

        for (int num : nums){
            if(num % 2 == 0) evenCount++;
            else oddCount++;
        }

        int expectedParity = nums[0] % 2;
        for (int num : nums){
            if(num % 2 == expectedParity){
                alternat++;
                expectedParity ^= 1;
            }
        }

        return max({evenCount,oddCount,alternat});


        
    }
};