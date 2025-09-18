class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        unordered_map<int , int> map;
        for(int i = 0;  i < n; i++){
            map[nums[i]]++;
        }

        for(auto pair : map){
            if(pair.second > n / 3){
                result.push_back(pair.first);
            }
        }
        return result;
        
    }
};