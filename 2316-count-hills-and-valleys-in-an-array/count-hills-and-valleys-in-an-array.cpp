class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int m = nums.size();
        int count = 0;
        if(m < 3) return 0;//if the array is less than 3 it can't form any hill or a vally
        
        //We have to remove the duplicates nums = [2,4,1,1,6,5]
        vector<int> noDupli;
        noDupli.push_back(nums[0]);
        for(int i = 1; i < m; i++){
            if(nums[i] != nums[i - 1]){
                noDupli.push_back(nums[i]);
            }
        }
        int n = noDupli.size();
        //Count the hills 
        for(int i = 1; i < n - 1 ; i++){
            if(noDupli[i] > noDupli[i - 1] && noDupli[i] > noDupli[i + 1]){
                count ++;
            }
        }
        //Count the vally;
        for(int i = 1; i < n - 1; i++){
            if(noDupli[i] < noDupli[i - 1] && noDupli[i] < noDupli[i + 1]){
                count ++;
            }
        }
        return count;
        
    }
};