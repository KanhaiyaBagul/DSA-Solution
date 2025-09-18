class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> s1(nums1.begin() , nums1.end());
        unordered_set<int> res;

        for(int num : nums2){
            if(s1.count(num)){
                res.insert(num);
            }
        }

        return {res.begin(),res.end()};
  
    }
};