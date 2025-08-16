class Solution {
public:
    int maximum69Number (int num) {
        vector<int> nums;

        int n = 0;
        while(num > 0){
            
            nums.push_back(num % 10);
            num = num / 10; 
        }

        reverse(nums.begin() , nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 6){
                nums[i] = 9;
                break;
            }
        }


        int m = 0;
        for(int i = 0; i < nums.size(); i++){
            m = m * 10 + nums[i];

        }
        return m;
    }
};