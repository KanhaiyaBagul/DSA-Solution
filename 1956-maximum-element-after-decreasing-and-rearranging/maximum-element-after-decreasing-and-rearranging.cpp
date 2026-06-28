class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            return 1;
        }
        sort(arr.begin(),arr.end());

        if(arr[0] != 1){
            arr[0] = 1;
        }
        int maxElement = 0;
        
        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1] > 1)){
                arr[i] = arr[i-1] + 1;
            }
            maxElement = max(maxElement , arr[i]);
        }
        return maxElement;

        
    }
};