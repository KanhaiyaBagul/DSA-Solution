class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        for(int i = 0; i < n; i++){
            //points for A
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j = 0; j < n; j++){
                bool valid = true;
                if(j == i) continue;
                //points for B
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x1 <= x2 && y1 >= y2){
                    //we find any overlapping is occure or not
                    for(int k = 0; k < n; k++){
                        if(k == i || k == j) continue;

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if(x3 >= x1 && x3 <= x2 &&   y3 <= y1 && y3 >= y2){
                            //if overlapping happen then break
                            valid = false;
                            break;
                        }
                    }
                    if(valid) result++;
                } 
                

            }
        }
        return result;

        
    }
};