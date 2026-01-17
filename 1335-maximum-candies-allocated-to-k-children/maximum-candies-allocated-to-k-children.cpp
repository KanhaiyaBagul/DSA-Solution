class Solution {
public:
    long long children(vector<int>& candies,long long mid){

        long long count = 0;
        for(long long c : candies){
            count += c / mid;
        }
        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) {

        long long totalCandies = accumulate(candies.begin(),candies.end(),0LL);


        long long low = 1;
        long long high = *max_element(candies.begin(),candies.end());

        if(totalCandies < k) return 0;
        long long ans = 0;

        while(low <= high){

            long long mid = low + (high - low) / 2;


            if(children(candies,mid) >= k){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            
        }
        return ans;

        
    }
};