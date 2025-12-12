class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>freq;

        for(int i = 0; i < s.size(); i++){
            freq[s[i]] = i;
        }

        int end = 0;
        int start = 0;
        vector<int> result;

        for(int i = 0; i < s.size(); i++){
            end = max(end,freq[s[i]]);

            if(i == end){
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result; 
    }
};