class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n =  nums.size();
        unordered_map<int , int > remainderIndex; // Create Hash map to store the remainder and the index 
        remainderIndex[0] = -1;

        int prefixSum = 0; // We calculate the prefixsum
        for(int i = 0; i < n; i++){
            prefixSum += nums[i]; //Prefix Sum
            int remainder;

            if(k != 0){
                remainder = prefixSum % k; // Calculate the remainder for every prefix sum 
                // This is the core logic 
                // If the two prefix sum's remainder is same it means there is a number who is multiple of K

            }

            //Here we find the remainder is already present or not
            if(remainderIndex.count(remainder)){
                // If it is present , We find the size of the subarray as mension in the probem
                if(i - remainderIndex[remainder] >= 2 ){
                    return true; // If the subarray size is greater than 2 or 2 it return the true

                }
            }
            else{
                remainderIndex[remainder] = i;//Here we insert the unique remainder in the Hash map , It is later use when a remainder is same as previous
            }
        }
        return false;  
    }
};