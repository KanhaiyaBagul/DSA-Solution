class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }
        
        vector<int> result;
        for(auto& pair : freq){
            if(pair.second == 2){
                result.push_back(pair.first);
            }
        }
        return result;
        
    }
};