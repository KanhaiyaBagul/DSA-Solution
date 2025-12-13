class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.empty()) return {newInterval};

        vector<vector<int>> ranges;
        bool insert = false;

        for(int i = 0; i < intervals.size(); i++){
            
            int start = intervals[i][0];

            if(!insert && start >= newInterval[0]){
                ranges.push_back(newInterval);
                insert = true;
            }
            ranges.push_back(intervals[i]);

        }

        if(!insert) ranges.push_back(newInterval);
        
        vector<vector<int>> result;

        int start1 = ranges[0][0];
        int end1 = ranges[0][1];

        for(int i = 1; i < ranges.size(); i++){
            int start2 = ranges[i][0];
            int end2 = ranges[i][1];

            if(end1 >= start2){
                start1 = start1;
                end1 = max(end1,end2);
                continue;
            }

            result.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        }
            result.push_back({start1,end1});
            return result;
        
    }
};