class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;//here we use set for unique elememts

        for(int num : nums){
            //if we find the element already in the set means this is the duplicate elemet and then we print true and then return
            if(set.find(num) != set.end()){
                return true;
            }
            set.insert(num);
        }
        return false;
        
    }
};