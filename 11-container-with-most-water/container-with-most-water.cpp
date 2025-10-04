class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;
        int height1;
        int width;
        int area;
        int maxWater = INT_MIN;

        while(i < j){
            height1 = min(height[i],height[j]);
            width = j - i;
            area = (height1 * width);
            maxWater = max(maxWater,area);

            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
            
        }

        return maxWater;
        
    }
};