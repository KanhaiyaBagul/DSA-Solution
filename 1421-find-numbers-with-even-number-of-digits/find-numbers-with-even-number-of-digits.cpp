class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int evenCount = 0;
        for(int i : nums){
            string str = to_string(i);
            if(str.size() % 2 == 0){
                evenCount++;
            }
        }
        return evenCount;
    }
};