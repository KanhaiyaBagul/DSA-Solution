class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result;
        int n = words.size();
        vector<int> prefix(n,0);
        set<char> s = {'a','e','i','o','u'};

        for(int i = 0; i < n; i++){
            char first = words[i][0];
            char last = words[i].back();

            int valid = (s.count(first) && s.count(last)) ? 1 : 0;

            prefix[i] = valid + (i > 0 ? prefix[i-1] : 0);
        }

        for(auto& p : queries){
            int l = p[0];
            int r = p[1];

            int count = prefix[r] - (l > 0 ? prefix[l-1] : 0);
            result.push_back(count);
        }
        return result;


        
    }
};