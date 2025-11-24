class Solution {
public:
    //this is the type of the prefix and suffix sum
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 0;
        suffix[n-1] = 0;

        for(int i = 1; i < n ; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
            suffix[n-i-1] = suffix[n-i] + nums[n-i];
        }

        for(int i = 0;i < n; i++){
            if(prefix[i] == suffix[i]){
                return i;
            }
        }
        return -1;
        
    }
};