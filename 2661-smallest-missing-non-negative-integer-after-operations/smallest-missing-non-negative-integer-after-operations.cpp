class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0);

        for(int i = 0;i < nums.size(); i ++){
            int r = (nums[i] % value + value) % value;
            freq[r]++;
        }


        int i = 0;

        while(true){
            int r = i % value;
            if(freq[r] > 0){
                freq[r]--;
            }else{
                return i;
            }
            i++;
        }

        return -1;
    }
    
};