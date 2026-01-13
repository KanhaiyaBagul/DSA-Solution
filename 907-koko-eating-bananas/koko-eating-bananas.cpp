class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low <= high){
            long long hours = 0;
            int mid = low + (high - low) / 2;

            for(auto &p : piles){
                hours += (p + mid - 1)/ mid;
            }

            if(hours > h){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
        
        
    }
};