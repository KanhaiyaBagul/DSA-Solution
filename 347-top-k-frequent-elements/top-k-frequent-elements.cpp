class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //first store the freq of each unique element 
        unordered_map<int, int> freq;

        for(auto& num : nums){
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto& pair : freq){
            pq.push({pair.second,pair.first});

        }

        vector<int> result;

        for(int i = 0; i < k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
  
    }
};