class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isMonotonic = false;

        if(is_sorted(nums.begin() , nums.end())){
            return !isMonotonic;
        }

         if(is_sorted(nums.begin() , nums.end(),greater<int>())){
            return !isMonotonic;
        }

        else{
            return isMonotonic;
        }
       

        
    }
};