class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for(int i = 0; i < patterns.size(); i++){
            string str = patterns[i];

            if(word.contains(str)){
                count++;
            }
        }
        return count;
        
    }
};