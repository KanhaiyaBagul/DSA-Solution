class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        
        unordered_map<string, int> s;

        int idx = 0;
        for(string str : strs){
            sort(str.begin(),str.end());
            string temp = str;

            if(!s.count(temp)){
                s[temp] = idx++;
            }
        }

        int rows = s.size();
        vector<vector<string>> result(rows);

        for(string str : strs){
            string st = str;
            sort(str.begin(),str.end());
            string temp = str;

            int idx = s[temp];
            result[idx].push_back(st);
        }
        return result;
    }
};