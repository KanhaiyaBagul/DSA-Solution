class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        string prev = "";
        vector<string> result;
        
        for(int i = 0; i < n ; i++){
            string temp = words[i];
            sort(temp.begin(),temp.end());//sort the curr element

            if(temp != prev){//if the previous is not equal then add to the vector
                result.push_back(words[i]);
                prev = temp;//update the preveious
            }
            
        }
        return result;
        
    }
};