class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub1;
        int maxLength = INT_MIN;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                sub1.push_back(nums[i]);
            }
        }

        maxLength = max(maxLength,(int)sub1.size()); //We use the int because the sub1.size is of "size_t" in the max fun we require the same type of type  


        sub1.clear();

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                sub1.push_back(nums[i]);
            }
        }

        maxLength = max(maxLength,(int)sub1.size());
        sub1.clear();


        int i = 0;
        bool flag = 0;

        if(nums[0] % 2 == 0){
            flag = 0;

        }

        else{
            flag = 1;
        }

        while(i < n){
            if(nums[i] % 2 == flag){
                sub1.push_back(nums[i]);
                flag = !flag;
            }
           

            i++;
        }

       maxLength = max(maxLength,(int)sub1.size());
        return maxLength;

        
    }
};