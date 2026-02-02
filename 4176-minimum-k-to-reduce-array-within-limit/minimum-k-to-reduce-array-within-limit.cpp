//Use Binary Search to find K
class Solution {
public:
    //this is use to calculate the total Hits 
    long long totalHits(vector<int>& nums, int k){
        long long hit = 0;
        for(int &num : nums){
            hit += (num + k - 1) / k;
        }
        return hit;
    }
    int minimumK(vector<int>& nums) {

        int low = 1;
        int high = 100000;
        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(totalHits(nums,mid) <= 1LL * mid * mid){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};