class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        int x = points[0][0];
        int y = points[0][1];

        for(int i = 1; i < points.size(); i++){
            int nx = points[i][0];
            int ny = points[i][1];

            result += max(abs(x-nx),abs(y-ny));
            x = nx;
            y = ny;
        }
        return result;
    }
};