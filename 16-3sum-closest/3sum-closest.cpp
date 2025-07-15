class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        int resultSum = nums[0] +  nums[1] + nums[2];
        int minDifference = INT_MAX;
        for(int base = 0; base < n - 2; base++){
          int left = base + 1;
          int right = n - 1;
          while(left < right){
            int sum = nums[base] + nums[left] + nums[right];
            if(sum == target) return target;
            if(sum < target) left ++;
            else right--;

            int diffToTarget = abs(sum - target);

            if(diffToTarget < minDifference){
                resultSum = sum;
                minDifference = diffToTarget;
            }


        
          }
          


        }
        return resultSum;
        
    }
};