class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0;

        unordered_map<int,int> freq;

        freq[0] = 1;
        int result = 0;

        for(int i = 0; i < nums.size();i++){
            //if the num is even then add "0" if odd then "1"
            sum += (nums[i] % 2 == 0) ? 0 : 1;

            //find the count of the sum - k freq in the hash table 
            int f = freq.count(sum - k) == 0 ? 0 : freq[sum - k];

            result += f;//add the freq of the sum - k element

            freq[sum]++;//add the founded sum here 

        }
        return result;
        
    }
};