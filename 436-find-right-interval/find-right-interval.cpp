class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //this vector store the starting value with their index
        vector<pair<int,int>> starts;

        int n = intervals.size();
        vector<int> result(n,-1);
        //we store here the starting value and the index
        for(int i = 0; i < n; i++){
            starts.push_back({intervals[i][0],i});
        }

        sort(starts.begin(),starts.end());//sort it

        //find the start is greater than the end for each interval, using the lower bound and store it in the result vector
        for(int i = 0; i < n; i++){
            int end = intervals[i][1];

            auto it = lower_bound(starts.begin(),starts.end(),make_pair(end,0));

            if(it != starts.end()){
                result[i] = it -> second;

            }
        }
        return result;
        
    }
};