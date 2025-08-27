class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        
        int result = 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int j = 0;
        int i = 0;

        while(i < n && j < m){
            if(s[j] >= g[i]){
                result++;
                i++;
                j++;

            }else{
                j++;
            }
        }
        return result;
        
    }
};