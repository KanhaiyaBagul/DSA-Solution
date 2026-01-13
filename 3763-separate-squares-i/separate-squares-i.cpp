class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double high = 0.0;
        double low = 1e18;

        for(auto& p : squares){
            double y = p[1];
            double l = p[2];

            totalArea += l * l;

            low = min(low,y);
            high = max(high,y+l);   
        }

        double target = totalArea / 2;

        for(int iter = 0; iter < 60; iter++){
            double mid = low + (high - low) / 2;
            double below = 0.0;

            for(auto &p : squares){
                double y = p[1];
                double l = p[2];

                if(mid <= y){
                    continue;
                }else if(mid >= y + l){
                    below += l * l;
                }else{
                    below += l * (mid - y);
                }

            }

            if(target > below){
                low = mid;
            }else{
                high = mid;
            }
        }
        return low;


        
    }
};