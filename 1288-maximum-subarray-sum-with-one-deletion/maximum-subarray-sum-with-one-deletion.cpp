class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDeletion = arr[0];
        int oneDeletion = INT_MIN;
        int result = arr[0];

        for(int i = 1; i < arr.size();i ++){
            int prevNoDeletion = noDeletion;
            int prevOneDeletion = oneDeletion;

            noDeletion = max(noDeletion + arr[i] , arr[i]);
            
            int v;
            if(prevOneDeletion == INT_MIN){//if their is not value in prevOne then store the arr[i] value
                v = arr[i];
            }else{
                v = prevOneDeletion + arr[i];//one deletion is already occure now add the curr arr[i]
            }

            oneDeletion = max(v,prevNoDeletion);

            result = max({result ,noDeletion, oneDeletion});
        }
        return result;
        
    }
};