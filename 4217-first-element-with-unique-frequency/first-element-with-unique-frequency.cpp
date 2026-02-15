class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }

        

        

        unordered_map<int,int> uniq;
        for(auto &p : freq){
            uniq[p.second]++;
        }

        
        for(int num : nums){
            if(uniq[freq[num]] == 1){
                return num;
            }
        }
        return -1;
        
    }
};