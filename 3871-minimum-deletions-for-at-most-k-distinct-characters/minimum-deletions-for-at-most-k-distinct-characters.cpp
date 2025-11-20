class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char , int> freq;
        for(char ch : s){
            freq[ch]++;
        }

        vector<int> arr; //we here store the freq and then sort it
        for(auto& pair : freq){
            arr.push_back(pair.second);
        }

        sort(arr.begin(),arr.end());

        int distinct = arr.size();
        int result = 0;
        int idx = 0;
        while(distinct > k){
            result += arr[idx++];
            distinct --; 
        }
        return result;
        
    }
};