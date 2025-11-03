class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        vector<vector<int>> result;

        int i = 0;
        while(i < n && intervals[i][1] < newStart){
            result.push_back(intervals[i]);
            i++;
        }

        
        while(i < n && intervals[i][0] <= newEnd){
            newStart = min(intervals[i][0],newStart);
            newEnd = max(intervals[i][1],newEnd);
            i++;           
        }
        result.push_back({newStart,newEnd});

        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;



        
    }
};