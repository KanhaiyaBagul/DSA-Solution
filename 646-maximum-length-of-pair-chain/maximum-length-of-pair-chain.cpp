class Solution {
public:

    static bool compare(vector<int> v1 , vector<int> v2){
        return v1[1]  < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin() , pairs.end() , compare);
        int result = 1;
        int currEnd = pairs[0][1];

        for(int i = 1; i < n; i++){
            if(pairs[i][0] > currEnd){
                result ++;
                currEnd = pairs[i][1];
            }
        }
        return result;

        
    }
};