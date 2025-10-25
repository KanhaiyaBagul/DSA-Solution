class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> s;

        //this function store the unique string with the index
        int idx = 0;
        for(string str : strs){
            sort(str.begin(),str.end());
            string temp = str;

            if(!s.count(temp)){
                s[temp] = idx++;
            }
        }

        //we find the identical element and store to the result with the help of the hash map 
        int rows = s.size();
        vector<vector<string>> result(rows);

        for(string str : strs){
            string oldString = str;//store the old string
            sort(str.begin(),str.end());//sort the permanent
            string temp = str;//this store the sorted string

            int idx = s[temp];//this is the index of the result 2d vector
            result[idx].push_back(oldString);//we push it accordingly
        }
        return result;
    }
};