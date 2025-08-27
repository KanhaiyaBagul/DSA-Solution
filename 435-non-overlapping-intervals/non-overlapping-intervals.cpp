class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<int> curr;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end() , [](const vector<int> &a , const vector<int> &b){
            return a[1] < b[1];
        });
        int last = intervals[0][1];

        int result = 0;


        for(int i = 1; i < n; i++){
            if(last > intervals[i][0]){
                result++; 
                
            }
            else{
                last = intervals[i][1];
            }
            
        }
        
        return result;

        
        
    }
};