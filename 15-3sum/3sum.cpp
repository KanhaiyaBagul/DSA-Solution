class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;//skip the duplicate element
            }

            //this pointer is use to solve smaller problem
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){//if sum > 0 means we have to reduce it 
                    k--;
                }else if(sum < 0){//increment the sum
                    j++;
                }else{
                    result.push_back({nums[i],nums[j], nums[k]});//if sum == 0
                    //shrink window size
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]){//remove the duplicate
                        j++;
                    }
                }
            }
            
        }
        return result;
        
        
    }
};