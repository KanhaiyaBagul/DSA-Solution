class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<int> last(26); 
        //first find the start ending of the each character
        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }

        int end = 0;
        int start = 0;
        vector<int> result;

        for(int i = 0; i < s.size(); i++){
            end = max(end,last[s[i] - 'a']);

            if(i == end){
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result; 
    }
};