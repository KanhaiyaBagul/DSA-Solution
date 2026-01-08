class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long mSum = 0;
        int left = 0;

        long long  sum = 0;
        unordered_map<int,int> freq;
        

        for(int right = 0; right < nums.size(); right++){
            int element = nums[right];
            sum += element;

            freq[element]++;

            while(right - left + 1 > k){
                sum -= nums[left];

                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);

                left++;
            }

            if(right - left + 1 == k && freq.size() >= m){
                mSum = max(mSum, sum);
            }
        }
        return mSum;
        
    }
};