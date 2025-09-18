class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        //first we calculate the req
        map<int , int> map;
        for(int i = 0;  i < n; i++){
            map[nums[i]]++;
        }

        //find the freq greater that n / 3
        for(auto pair : map){
            if(pair.second > n / 3){
                result.push_back(pair.first);
            }
        }
        return result;
        
    }
};