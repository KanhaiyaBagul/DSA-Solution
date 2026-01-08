    class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            long long maxSum = 0;
            int left = 0;
            long long sum = 0;
            unordered_map<int,int> m;
            

            for(int right = 0; right < nums.size(); right++){
                int element = nums[right];
                sum += element;
                m[element]++;

                while(right - left + 1 > k){
                    sum -= nums[left];
                    m[nums[left]]--;
                    if(m[nums[left]] == 0) m.erase(nums[left]);
                    

                    left++;
                }

                if(right - left + 1 == k && m.size() == k){
                    maxSum = max(maxSum , sum);

                }

            }
            return maxSum;
            
        }
    };