class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num = 0;
        vector<bool> result(nums.size());

        for(int i = 0; i < nums.size();i++){
            num = (num * 2) % 5 + nums[i];//this left the value  it is use full to add the nums element as bit

            if(num % 5 == 0){
                result[i] = true;
            }else{
                result[i] = false;
            }
        }
        return result;
    }
};