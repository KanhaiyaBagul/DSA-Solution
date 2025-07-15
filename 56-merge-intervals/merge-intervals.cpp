class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merge;
        merge.push_back(intervals[0]);

       for (int i = 1; i < intervals.size();i++){
         vector<int>& last = merge.back();
         vector<int>& current = intervals[i];

         if(last[1] >= current[0]){
            last[1] =max(last[1], current[1]);

         }
         else{
            merge.push_back(current);
            
         }
       } 
       return merge;
        
    }
};